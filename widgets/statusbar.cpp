#include "statusbar.h"

StatusBar::StatusBar(QWidget* parent) : QWidget(parent) {
	setAttribute(Qt::WA_StyledBackground, true);
	setFixedHeight(24);
	setStyleSheet("background: #007acc;");
}
