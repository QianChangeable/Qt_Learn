#pragma once

#include <QWidget>

class QPushButton;

class MainWindow : public QWidget {
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);

private slots:
	void onButtonClicked();

private:
	QPushButton* m_button = nullptr;
};