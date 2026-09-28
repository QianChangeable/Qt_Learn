#include <QApplication>
#include <QPushButton>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("Hello, Qt!");
	window.resize(1200, 900);

	QPushButton* button = new QPushButton("Click me!");
	QHBoxLayout* HLayout = new QHBoxLayout();

	button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	HLayout->addStretch(1);
	HLayout->addWidget(button, 2);
	HLayout->addStretch(1);

	QVBoxLayout* VLayout = new QVBoxLayout(&window);
	VLayout->addStretch(1);
	// VLayout->addWidget(HLayout, 2, Qt::AlignHCenter);
	// 这玩意不是widget，不能按照widget加。
	VLayout->addLayout(HLayout, 2);
	VLayout->addStretch(1);

	window.show();

	return app.exec();
}