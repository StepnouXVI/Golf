#include <Ui/Settings.h>
#include <Ui/Styles/Styles.h>
#include <Ui/Widgets/LeaderBoardWidget.h>

using namespace Ui;

QPushButton *createButton();
void setTitle();
void setScrollableArea();
LeaderBoardWidget::LeaderBoardWidget(Domain::GamePtr game, QWidget *parent) : QWidget(parent), _game(game)
{

    auto layout = new QGridLayout(this);

    auto button = createButton();
    setTitle();
    setScrollableArea();

    layout->addWidget(button, 0, 0, 1, 2);
    layout->addWidget(_title.get(), 0, 2, 1, 4);
    layout->addWidget(_leaderboard.get(), 1, 0, 4, 6);

    setLayout(layout);
}

QPushButton *LeaderBoardWidget::createButton()
{
    auto button = new QPushButton("Update Leaderboard", this);
    button->setMinimumSize(1.5*2 * Settings::Instance().CellSetting().W, Settings::Instance().CellSetting().H);
    button->setStyleSheet(Styles::UpdateButton);

    auto font = button->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    button->setFont(font);
    connect(button, &QPushButton::clicked, this, &LeaderBoardWidget::onPushButton);
    return button;
}

void LeaderBoardWidget::setTitle()
{
    _title = std::make_shared<QLabel>("Leaderboard");
    _title->setAlignment(Qt::AlignCenter);

    auto font = _title->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H * 0.75);
    font.setItalic(true);
    _title->setFont(font);
    _title->setMinimumSize(1.5*4 * Settings::Instance().CellSetting().W, Settings::Instance().CellSetting().H);
}

void LeaderBoardWidget::setScrollableArea()
{
    _leaderboard = std::make_shared<ScrollableList>(this);
    _leaderboard->setMinimumSize(1.5*6 * Settings::Instance().CellSetting().W, 4 * Settings::Instance().CellSetting().H);
}

void LeaderBoardWidget::onPushButton()
{
    int i = 1;
    _leaderboard->ClearItems();

    auto leaderboardData = _game->MakeLeaderBoard();
    for (auto &record : (*leaderboardData))
    {

        auto label = makeLabel(QString::number(i) + ") \"" + QString::fromStdString(record.first) +
                               "\": " + QString::number(record.second));
        _leaderboard->AddItem(label);
        i++;
    }
}

QLabel *LeaderBoardWidget::makeLabel(QString str)
{
    auto label = new QLabel(str, this);
    label->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    label->setStyleSheet(Styles::OutputLineStyle);
    label->setMaximumHeight(Settings::Instance().CellSetting().H);

    auto font = label->font();
    font.setBold(true);
    font.setPixelSize(Settings::Instance().CellSetting().H / 2);
    font.setItalic(true);
    label->setFont(font);
    return label;
}
