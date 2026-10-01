#include "sidebar.h"

#include <QDir>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>

SideBar::SideBar(QWidget* parent) : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedWidth(260);
    setStyleSheet(
        "SideBar { background: #252526; }"
        "QPushButton {"
        "  color: #ffffff;"
        "  background: #0e639c;"
        "  border: none;"
        "  border-radius: 4px;"
        "  padding: 6px 10px;"
        "}"
        "QPushButton:hover { background: #1177bb; }");

    m_createDir = new QPushButton("选择工作目录", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(12, 12, 12, 12);
    layout->setSpacing(8);
    layout->addWidget(m_createDir);
    layout->addStretch(1);

    connect(m_createDir, &QPushButton::clicked, this, &SideBar::onCreateDirClicked);
}

void SideBar::onCreateDirClicked() {
    const QString dir = QFileDialog::getExistingDirectory(
        this,
        tr("选择工作目录"),
        m_workingDirectory.isEmpty() ? QDir::homePath() : m_workingDirectory);

    if (dir.isEmpty()) {
        return; // 用户取消
    }

    m_workingDirectory = dir;
    emit workingDirectoryLocation(dir);
}
