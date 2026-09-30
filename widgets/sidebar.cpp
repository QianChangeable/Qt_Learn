#include "sidebar.h"

SideBar::SideBar(QWidget* parent) : QWidget(parent) {
	setAttribute(Qt::WA_StyledBackground, true);
	setFixedWidth(260);
	setStyleSheet("background: #252526;");
}
