#include "mainwindow.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Hello, Qt!");
	resize(1200, 900);

	m_button = new QPushButton("Click me!", this);
	m_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_lineEdit = new QLineEdit(this);
	m_lineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout* centerColumn = new QVBoxLayout();
	centerColumn->addWidget(m_lineEdit);
	centerColumn->addWidget(m_button, 2);

	QHBoxLayout* HLayout = new QHBoxLayout();
	HLayout->addStretch(1);
	HLayout->addLayout(centerColumn, 2);
	HLayout->addStretch(1);

	QVBoxLayout* VLayout = new QVBoxLayout(this);
	VLayout->addStretch(1);
	VLayout->addLayout(HLayout, 2);
	VLayout->addStretch(1);

	connect(m_button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

	connect(m_lineEdit, &QLineEdit::textChanged, this, &MainWindow::onTextChanged);

	connect(this, &MainWindow::textEdited, this, &MainWindow::onTextEdited);
}

void MainWindow::onButtonClicked() {
	m_button->setText("Clicked!");
}

void MainWindow::onTextChanged(const QString& text) {
	m_button->setText(text);
	emit textEdited(text);
}

void MainWindow::onTextEdited(const QString& text) {
	setWindowTitle(text.isEmpty() ? "Hello, Qt!" : text);
}