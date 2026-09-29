#include "mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Hello, Qt!");
	resize(1200, 900);

	m_button = new QPushButton("Click me!", this);
	m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QHBoxLayout* HLayout = new QHBoxLayout();
	HLayout->addStretch(1);
	HLayout->addWidget(m_button, 2);
	HLayout->addStretch(1);

	QVBoxLayout* VLayout = new QVBoxLayout(this);
	VLayout->addStretch(1);
	VLayout->addLayout(HLayout, 2);
	VLayout->addStretch(1);

	connect(m_button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked() {
	m_button->setText("Clicked!");
}