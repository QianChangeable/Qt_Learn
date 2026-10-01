#include "activitybar.h"

#include <QPushButton>
#include <QVBoxLayout>

ActivityBar::ActivityBar(QWidget* parent) : QWidget(parent) {
	setAttribute(Qt::WA_StyledBackground, true);
	setFixedWidth(48);
	setStyleSheet("background: #333333;");

	m_blogButton = new QPushButton("博", this);
	m_blogButton->setFixedSize(40, 40);
	m_blogButton->setToolTip("博客");
	m_blogButton->setStyleSheet(
		"QPushButton {"
		"  color: #cccccc;"
		"  background: transparent;"
		"  border: none;"
		"  border-radius: 6px;"
		"}"
		"QPushButton:hover {"
		"  background: #3c3c3c;"
		"}");

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setContentsMargins(4, 8, 4, 8);
	layout->setSpacing(4);
	layout->addWidget(m_blogButton, 0, Qt::AlignHCenter);
	layout->addStretch(1);
}
