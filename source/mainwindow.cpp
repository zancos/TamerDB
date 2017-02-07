#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setWindowTitle(tr("Tamer Database"));

	//QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	//QSqlDatabase db;
	//db.addDatabase("QMYSQL");
	//db.setHostName("192.168.10.146");
	//db.setDatabaseName("");
	//db.setUserName("root");
	//db.setPassword("");
	//bool ok = db.open();

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");


}

MainWindow::~MainWindow()
{
	delete ui;
}