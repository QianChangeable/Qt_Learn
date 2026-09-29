#pragma once

#include <QWidget>

class QPushButton;

class mainWindow : public QWidget {
	Q_OBJECT
public:
	explicit mainWindow(QWidget* parent = nullptr);

private slots:
	void onButtonClicked();

private:
	QPushButton* m_button = nullptr;
};