#include "sidebar.h"

#include <QPushButton>

SideBar::SideBar(QWidget* parent) : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedWidth(260);
    setStyleSheet("background: #252526;");

    m_createDir = new QPushButton(this);
}
