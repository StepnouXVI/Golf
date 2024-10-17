#pragma once

#include <QListWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>


#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <set>
#include <string>


namespace Ui
{
class ScrollableList : public QScrollArea
{
    Q_OBJECT

  public:
    ScrollableList(QWidget *parent = nullptr);
    void AddItem(QWidget *item);
    void ClearItems();
};
} // namespace Ui