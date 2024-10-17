#ifndef STYLES_H
#define STYLES_H

#include <QString>
namespace Ui::Styles
{

const QString ScrollAreaStyle = R"(
QScrollArea {
    background-color: #b2b2b2;
}

QScrollArea QWidget {
    background-color: transparent;
}
)";

const QString TabWidgetStyle = R"(
    QTabWidget::pane{
        border: none;
        background-color:white;
      }
    QTabBar::tab{
        color: #1A2030
    }
    )";

const QString InputLineStyle = R"(
    QLineEdit {
      color: #1A2030;
      border-bottom: 1px solid #1A2030;
      background-color: white;
      margin-left: 7;
      margin-right: 7;
    })";

const QString OutputLineStyle = R"(
    QLabel {
      color: #1A2030;
      border: 1px solid #1A2030;
      background-color: white;
      margin-bottom: 0;
    })";

const QString UpdateButton = R"(
QPushButton {
    border: none;
    border-radius: 5;
    background-color: #2d3146;
    color: white;
}
QPushButton:hover { background-color: #373b49; }
QPushButton:pressed { background-color: #2d3146; }
)";
} // namespace Ui::Styles

#endif // STYLES_H
