#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QSettings>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDesktopWidget myDesktop;
	MainWindow w;

	// Core Application
	QCoreApplication::setApplicationName("Tamer Database");
	QCoreApplication::setApplicationVersion("0.0.1");
	QCoreApplication::setOrganizationName("Ploding");
	QCoreApplication::setOrganizationDomain("ploding.com");


	// Config file
	QSettings *settings;
	const QString settingFilePath = QDir::currentPath() + "/configTamerDB.ini";
	qDebug() << "Config file directory:" << settingFilePath;
	QFile configInitFile(settingFilePath);
	settings = new QSettings(settingFilePath, QSettings::IniFormat);

	if (!configInitFile.exists())
	{
		QMessageBox::StandardButtons fileMessage;
		fileMessage = QMessageBox::question(0, "Error al cargar la Configuracion", "No se encuentra el archivo de configuracion\n Desea Crearlo", QMessageBox::Yes | QMessageBox::No);
		if (fileMessage == QMessageBox::Yes)
		{
			qDebug() << "YES";
			settings->beginGroup("db");
			settings->setValue("dbHost", "0.0.0.0");
			settings->setValue("dbPort", 3306);
			settings->setValue("dbUser", "root");
			settings->setValue("dbPass", "");
			settings->setValue("dbName", "TamerDB");
			settings->endGroup();
			// qDebug() << settings->value("dbHost");
		}
		else
		{
			return 1;
		}
	}


	// Look for Area and dimensions
	int desktopArea = QApplication::desktop()->width() * QApplication::desktop()->height();
	int widgetArea = w.width() * w.height();
	//desktopArea = myDesktop.width() * myDesktop.height();
	//int avDesktopArea = myDesktop.availableGeometry.height() * myDesktop.availableGeometry.width();

	if (((float)widgetArea / (float)desktopArea) < 0.75f)
		w.show();
	else
		w.showMaximized();

	

	

	return a.exec();
}
