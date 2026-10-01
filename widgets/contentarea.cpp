#include "contentarea.h"

#include <QLabel>
#include <QVBoxLayout>

ContentArea::ContentArea(QWidget* parent) : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("background: #1e1e1e;");

    m_pathLabel = new QLabel("未选择工作目录", this);
    m_pathLabel->setStyleSheet("color: #cccccc; padding: 12px;");
    m_pathLabel->setWordWrap(true);  // 文字过长时自动换行

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_pathLabel);
    layout->addStretch(1);
}

void ContentArea::setWorkingDirectoryLocation(const QString& path) {
    m_pathLabel->setText(path);     // 改标签上显示的文字
    m_pathLabel->setToolTip(path);  // 鼠标悬停时弹出的提示
}