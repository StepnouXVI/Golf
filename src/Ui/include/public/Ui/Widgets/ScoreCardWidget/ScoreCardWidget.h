#pragma once
#include <Domain/Game.h>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>
#include <memory>

namespace Ui
{
class ScoreCardWidget : public QWidget
{
    Q_OBJECT

  private:
    std::shared_ptr<QTableWidget> _tableWidget;
    std::shared_ptr<QLabel> _nameLine;
    Domain::ScoreCardPtr _scoreCard;
    bool _silence = false;

  private:
    QPushButton *createAddNewPlayerButton();
    void configureTableWidget();
    void setTableWidgetHeader();
    void createNameLine(const std::string name);
    void fillPars();

  public:
    explicit ScoreCardWidget(Domain::ScoreCardPtr scoreCard, QWidget *parent = nullptr);

  public slots:
    void onItemChanged(QTableWidgetItem *item);
    void onUpdatePar();
  signals:
    void updatePar();
};
} // namespace Ui
