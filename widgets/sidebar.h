#pragma once

#include <QWidget>

class QPushButton;
class SideBar : public QWidget {
    Q_OBJECT
public:
    explicit SideBar(QWidget* parent = nullptr);

signals:
    void workingDirectoryLocation(const QString& path);

private slots:
    void onCreateDirClicked();

private:
    QPushButton* m_createDir = nullptr;
    QString m_workingDirectory;
};
