#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include "ui_mainwindow.h"
#include "configuration.h"
#include "acercade.h"


namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();


private slots:
	void on_actionConfiguracion_triggered();
	void on_botonSiguiente_clicked();
	void on_actionAcercade_triggered();


private:
	Ui::MainWindow *ui;
	ConfigurationDialog *myConfigurationDialog;
	acercadeDialog *myAcercadeDialog;
};