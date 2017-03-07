#include "acercade.h"
#include <QDebug>


acercadeDialog::acercadeDialog(QWidget *parent) :
QDialog(parent),
ui(new Ui::acercadeDialog)
{
	ui->setupUi(this);
}

acercadeDialog::~acercadeDialog()
{
	delete ui;
}

void acercadeDialog::on_pushButton_close_acercade_clicked()
{
	qDebug() << "Clicked";
	this->close();

}

/*
void acercadeDialog::pushButton_close_db_config()
{
	qDebug() << "Clicked";
}
*/