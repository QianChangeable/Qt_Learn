#include <QApplication>

#include "mainwindow.h"

#ifdef Q_OS_MAC
#include "platform/macos_window.h"
#endif

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow window;
	window.show();

#ifdef Q_OS_MAC
	applyMacDarkWindow(window.winId());
#endif

	return app.exec();
}
