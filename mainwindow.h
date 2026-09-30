#pragma once

#include <QWidget>

class TitleBar;
class ActivityBar;
class SideBar;
class ContentArea;
class StatusBar;

class MainWindow : public QWidget {
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);

private:
	TitleBar* m_titleBar = nullptr;
	ActivityBar* m_activityBar = nullptr;
	SideBar* m_sideBar = nullptr;
	ContentArea* m_contentArea = nullptr;
	StatusBar* m_statusBar = nullptr;
};
