#pragma once

#include <QWidget>

class QPushButton;
class SideBar : public QWidget {
    Q_OBJECT
public:
    explicit SideBar(QWidget* parent = nullptr);

private:
    QPushButton* m_createDir = nullptr;
};
