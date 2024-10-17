
#include <Domain/Game.h>
#include <Ui/Main/MainWindow.h>
#include <Ui/Settings.h>
#include <Ui/Widgets/LeaderBoardWidget.h>
#include <Ui/Widgets/ScoreCardWidget/ScoreCardsWidgets.h>


#include <QApplication>

using namespace Ui;

int main(int argc, char *argv[])
{
    Settings::Instance().CellSetting().W = 175;
    Settings::Instance().CellSetting().H = 100;

    auto pars = std::make_shared<std::vector<int>>(18, 0);
    auto game = std::make_shared<Domain::Game>(pars);

    QApplication app(argc, argv);

    auto tabs = map<string, QWidget *>();
    tabs["Leaderboard"] = new Ui::LeaderBoardWidget(game);
    tabs["Score Cards"] = new Ui::ScoreCardsWidget(game);
    MainWindow main_window(tabs);
    main_window.show();
    // app.setStyle("fusion");
    return app.exec();
}
