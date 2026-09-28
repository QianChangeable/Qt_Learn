#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("Hello, Qt!");
	window.resize(1200, 900);

	QPushButton* button = new QPushButton("Click me!");
	QVBoxLayout* layout = new QVBoxLayout(&window);
	layout->addWidget(button);

	window.show();

	return app.exec();
}