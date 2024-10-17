#include <Ui/Settings.h>
#include <Ui/Styles/Styles.h>
#include <Ui/Widgets/ScoreCardWidget/ScoreCardWidget.h>
#include <Ui/Widgets/ScoreCardWidget/ScoreCardsWidgets.h>

using namespace Ui;
ScoreCardsWidget::ScoreCardsWidget(Domain::GamePtr game, QWidget *parent) : QWidget{parent}, _game(game)
{
    setNameLine();
    setScrollableArea();
    auto layout = new QGridLayout(this);
    auto button = createButton();

    layout->addWidget(button, 0, 0, 1, 2);
    layout->addWidget(_nameLine.get(), 0, 2, 1, 4);
    layout->addWidget(_scoreCardList.get(), 1, 0, 4, 6);

    setLayout(layout);
}

QPushButton *ScoreCardsWidget::createButton()
{
    auto button = new QPushButton("Add new player", this);
    button->setMinimumSize(1.5*2 * Settings::Instance().CellSetting().W, Settings::Instance().CellSetting().H);
    button->setStyleSheet(Styles::UpdateButton);

    auto font = button->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    button->setFont(font);
    connect(button, &QPushButton::clicked, this, &ScoreCardsWidget::onPushButton);
    return button;
}

void ScoreCardsWidget::setNameLine()
{
    // line settings
    auto inputString = std::make_shared<QLineEdit>();
    inputString->setMinimumSize(1.5*4 * Settings::Instance().CellSetting().W, Settings::Instance().CellSetting().H);
    inputString->setStyleSheet(Styles::InputLineStyle);
    // text style settings
    inputString->setMaxLength(256);
    inputString->setPlaceholderText("Name");
    inputString->setAlignment(Qt::AlignCenter);
    // font settings
    auto font = inputString->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H * 0.75);
    font.setItalic(true);
    inputString->setFont(font);

    _nameLine = inputString;
}
void ScoreCardsWidget::setScrollableArea()
{
    _scoreCardList = std::make_shared<ScrollableList>(this);
    _scoreCardList->setMinimumSize(1.5*6 * Settings::Instance().CellSetting().W, 4 * Settings::Instance().CellSetting().H);
}

void ScoreCardsWidget::onPushButton()
{
    auto name = _nameLine->text();
    if (!name.isEmpty())
    {
        auto std_name = name.toStdString();
        _game->AddPlayer(std_name);
        auto item = new ScoreCardWidget(_game->GetPlayerCard(std_name), this);
        connect(item, &ScoreCardWidget::updatePar, this, &ScoreCardsWidget::onParUpdated);
        connect(this, &ScoreCardsWidget::updatePar, item, &ScoreCardWidget::onUpdatePar);
        _scoreCardList->AddItem(item);
    }
}

void ScoreCardsWidget::onParUpdated()
{
    emit updatePar();
}
