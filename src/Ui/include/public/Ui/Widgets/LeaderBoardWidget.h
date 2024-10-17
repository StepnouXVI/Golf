#pragma once

#pragma once

#include <QLabel>
#include <QPushButton>

#include <Domain/Game.h>
#include <QWidget>
#include <Ui/Widgets/ScrollableList.h>
#include <memory>


namespace Ui
{
class LeaderBoardWidget : public QWidget
{
    Q_OBJECT

  private:
    std::shared_ptr<ScrollableList> _leaderboard;
    std::shared_ptr<QLabel> _title;
    Domain::GamePtr _game;

  private:
    QPushButton *createButton();
    void setTitle();
    void setScrollableArea();
    QLabel *makeLabel(QString str);

  public:
    explicit LeaderBoardWidget(Domain::GamePtr game, QWidget *parent = nullptr);
  public slots:
    void onPushButton();
};
} // namespace Ui
