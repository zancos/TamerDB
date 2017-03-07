#include "configuration.h"
#include <QDebug>

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
QDialog(parent),
ui(new Ui::ConfigurationDialog)
{
	ui->setupUi(this);
}

ConfigurationDialog::~ConfigurationDialog()
{
	delete ui;
}

void ConfigurationDialog::on_pushButton_save_db_config_clicked()
{
	qDebug() << "Clicked";
}

void ConfigurationDialog::pushButton_close_db_config()
{
	qDebug() << "Clicked";
}