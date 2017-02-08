#include "mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	setWindowTitle(tr("Tamer Database"));

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.75.128");
	db.setDatabaseName("tamerdb");
	db.setUserName("root");
	db.setPassword("");
	bool ok = db.open();
	db.close();
	qDebug() << "Conexión db:" << ok;


}

MainWindow::~MainWindow()
{
	delete ui;
}