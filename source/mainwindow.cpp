#include <QDebug>
#include "mainwindow.h"
#include "configuration.h"


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	setWindowTitle(tr("Tamer Database"));

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("bbdd.ploding.com");
	db.setDatabaseName("ddb91739");
	db.setUserName("ddb91739");
	db.setPassword("k%BiO2PmOc;l");
	bool ok = db.open();
	qDebug() << "Conexión db:" << ok;
	db.close();
	
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_actionConfiguracion_triggered()
{
	qDebug() << "triggered";
	myConfigurationDialog = new ConfigurationDialog(this);
	myConfigurationDialog->setModal(true);
	myConfigurationDialog->show();
}

void MainWindow::on_botonSiguiente_clicked()
{
	qDebug() << "pushed";
}

void MainWindow::on_actionAcercade_triggered()
{
	qDebug() << "triggered";
	myAcercadeDialog = new acercadeDialog(this);
	myAcercadeDialog->setModal(true);
	myAcercadeDialog->show();
}