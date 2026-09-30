#include "mainwindow.h"

#include "widgets/activitybar.h"
#include "widgets/contentarea.h"
#include "widgets/sidebar.h"
#include "widgets/statusbar.h"
#include "widgets/titlebar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Hello, Qt!");
	resize(1200, 800);

	m_titleBar = new TitleBar(this);
	m_activityBar = new ActivityBar(this);
	m_sideBar = new SideBar(this);
	m_contentArea = new ContentArea(this);
	m_statusBar = new StatusBar(this);

	QVBoxLayout* rightColumn = new QVBoxLayout();
	rightColumn->setContentsMargins(0, 0, 0, 0);
	rightColumn->setSpacing(0);
	rightColumn->addWidget(m_titleBar);
	rightColumn->addWidget(m_contentArea, 1);

	QHBoxLayout* middleRow = new QHBoxLayout();
	middleRow->setContentsMargins(0, 0, 0, 0);
	middleRow->setSpacing(0);
	middleRow->addWidget(m_activityBar);
	middleRow->addWidget(m_sideBar);
	middleRow->addLayout(rightColumn, 1);

	QVBoxLayout* root = new QVBoxLayout(this);
	root->setContentsMargins(0, 0, 0, 0);
	root->setSpacing(0);
	root->addLayout(middleRow, 1);
	root->addWidget(m_statusBar);
}
