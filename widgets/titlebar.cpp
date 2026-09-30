#include "titlebar.h"

TitleBar::TitleBar(QWidget* parent) : QWidget(parent) {
	setAttribute(Qt::WA_StyledBackground, true);
	setFixedHeight(40);
	setStyleSheet("background: #3c3c3c;");
}
