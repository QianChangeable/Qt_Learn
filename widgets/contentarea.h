#pragma once

#include <QWidget>

class QLabel;

class ContentArea : public QWidget {
	Q_OBJECT
public:
	explicit ContentArea(QWidget* parent = nullptr);

public slots:
	void setWorkingDirectoryLocation(const QString& path);

private:
	QLabel* m_pathLabel = nullptr;
};
