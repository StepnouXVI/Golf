#include <QGridLayout>
#include <Ui/Settings.h>
#include <Ui/Widgets/ScoreCardWidget/ScoreCardWidget.h>

namespace Ui
{
ScoreCardWidget::ScoreCardWidget(Domain::ScoreCardPtr scoreCard, QWidget *parent)
    : QWidget(parent), _scoreCard(scoreCard)
{

    createNameLine(scoreCard->GetPlayerName());
    configureTableWidget();
    setTableWidgetHeader();

    auto layout = new QGridLayout(this);

    layout->addWidget(_nameLine.get(), 0, 0, 1, 5);
    layout->addWidget(_tableWidget.get(), 1, 0, 1, 5);

    setLayout(layout);

    connect(_tableWidget.get(), &QTableWidget::itemChanged, this, &ScoreCardWidget::onItemChanged);
    fillPars();
}

void ScoreCardWidget::configureTableWidget()
{
    _tableWidget = std::make_shared<QTableWidget>(this);
    _tableWidget->setColumnCount(18);
    _tableWidget->setRowCount(3);
    // Add your code to configure the table widget here
}

void ScoreCardWidget::setTableWidgetHeader()
{
    QStringList columnHeaderLabels;
    for (int i = 0; i < 9; i++)
    {
        columnHeaderLabels << QString::number(i + 1);
    }

    for (int i = 9; i < 18; i++)
    {
        columnHeaderLabels << QString::number(i + 1);
    }

    _tableWidget->setHorizontalHeaderLabels(columnHeaderLabels);

    QStringList rowHeaderLabels = {"Par", "Handicap", "Stroke"};
    _tableWidget->setVerticalHeaderLabels(rowHeaderLabels);
}

void ScoreCardWidget::onItemChanged(QTableWidgetItem *item)
{
    switch (item->row())
    {
    case 0: {
        _scoreCard->SetPar(item->column(), item->text().toInt());
        if (!_silence)
            emit updatePar();
    }
    break;
    case 1: {
        _scoreCard->SetHandicap(item->column(), item->text().toInt());
    }
    break;
    case 2: {
        _scoreCard->RecordStrokes(item->column(), item->text().toInt());
    }
    break;
    }
}

void ScoreCardWidget::onUpdatePar()
{
    fillPars();
}

void ScoreCardWidget::fillPars()
{
    _silence = true;
    for (int i = 0; i < _scoreCard->GetHoleCount(); i++)
    {
        _tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(_scoreCard->GetParForHole((size_t)i))));
    }
    _silence = false;
}

void ScoreCardWidget::createNameLine(const std::string name)
{
    _nameLine = std::make_shared<QLabel>(this);

    _nameLine->setText(name.c_str());
    _nameLine->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

    auto font = _nameLine->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    font.setItalic(true);
    _nameLine->setFont(font);
}
} // namespace Ui
