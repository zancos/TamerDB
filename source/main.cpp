#include <QApplication>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QSettings>
#include <QDebug>
#include <QtPlugin>

#include <boost\locale.hpp>
#include <iostream>

#include "mainwindow.h"
//#include "settings.h"

int main(int argc, char *argv[])
{
	/* no funciona
    std::locale::global(std::locale("Spanish"));
    std::wstring cad = L"Hola, ¿qué tal estás?";
    std::wcout << cad;
	*/

    //string utf8_string = to_char<�>;
	//boost::locale
    //string utf8_string = to_utf<char>(latin1_string,"Latin1");
    //std::string latin1_string;
    //std::string utf8_string = boost::locale::conv::to_utf<char>(latin1_string,"Latin1");

	QApplication a(argc, argv);
	QDesktopWidget myDesktop;
	MainWindow w;

	// Core Application
	QCoreApplication::setApplicationName("Tamer Database");
	QCoreApplication::setApplicationVersion("0.0.1");
	QCoreApplication::setOrganizationName("Ploding");
	QCoreApplication::setOrganizationDomain("ploding.com");
	a.setWindowIcon(QPixmap(":icono.png"));

	// Config file
	const QString settingFilePath = QDir::currentPath() + "/configTamerDB.ini";
	QSettings *settings = new QSettings(settingFilePath, QSettings::IniFormat);
	qDebug() << "Config file directory:" << settingFilePath;
	QFile configInitFile(settingFilePath);
	

	if (!configInitFile.exists())
	{
		QMessageBox::StandardButtons fileMessage;
		fileMessage = QMessageBox::question(0, "Error al cargar la Configuracion", "No se encuentra el archivo de configuracion\n�Desea Crearlo?", QMessageBox::Yes | QMessageBox::No);
		if (fileMessage == QMessageBox::Yes)
		{
			qDebug() << "YES";
			settings->beginGroup("db");
			settings->setValue("dbHost", "127.0.0.1");
			settings->setValue("dbPort", 3306);
			settings->setValue("dbUser", "root");
			settings->setValue("dbPass", "");
			settings->setValue("dbName", "TamerDB");
			settings->endGroup();
			qDebug() << settings->value("dbHost");
		}
		else
		{
			return 1;
		}
	}

	// Debug options
	//foreach(const QString &path, a.libraryPaths()); dosomething(a);

	w.show();

	return a.exec();
}
