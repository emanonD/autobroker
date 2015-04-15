#include "main_window.h"
#include "dbase/dbase.h"

#include <QApplication>
//extern dbase db;
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MainWindow mainWindow;

	mainWindow.show();

	return app.exec();
}