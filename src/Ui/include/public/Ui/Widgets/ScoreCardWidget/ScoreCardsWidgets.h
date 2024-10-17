#ifndef SCORECARDSWIDGETS_H
#define SCORECARDSWIDGETS_H

#include <Domain/Game.h>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <Ui/Widgets/ScrollableList.h>

namespace Ui
{

class ScoreCardsWidget : public QWidget
{
    Q_OBJECT

  private:
    Domain::GamePtr _game;
    std::shared_ptr<QLineEdit> _nameLine;
    std::shared_ptr<Ui::ScrollableList> _scoreCardList;

  private:
    QPushButton *createButton();
    void setNameLine();
    void setScrollableArea();

  public:
    explicit ScoreCardsWidget(Domain::GamePtr game, QWidget *parent = nullptr);
  public slots:
    void onPushButton();
    void onParUpdated();
  signals:
    void updatePar();
};
} // namespace Ui
#endif // SCORECARDSWIDGETS_H
