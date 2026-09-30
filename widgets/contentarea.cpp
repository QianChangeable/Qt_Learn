#include "contentarea.h"

ContentArea::ContentArea(QWidget* parent) : QWidget(parent) {
	setAttribute(Qt::WA_StyledBackground, true);
	setStyleSheet("background: #1e1e1e;");
}
