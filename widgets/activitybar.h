#pragma once

#include <QWidget>

class QPushButton;

class ActivityBar : public QWidget {
	Q_OBJECT
public:
	explicit ActivityBar(QWidget* parent = nullptr);

private:
	QPushButton* m_blogButton = nullptr;
};
