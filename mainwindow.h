#pragma once

#include <QWidget>

class QPushButton;

class QLineEdit;

class MainWindow : public QWidget {
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);

private slots:
	void onButtonClicked();
	void onTextChanged(const QString& text);

private:
	QPushButton* m_button = nullptr;
	QLineEdit* m_lineEdit = nullptr;
};