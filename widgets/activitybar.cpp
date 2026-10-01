#include "activitybar.h"

#include <QPushButton>
#include <QVBoxLayout>

ActivityBar::ActivityBar(QWidget* parent) : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedWidth(48);
    setStyleSheet("background: #333333;");
}
