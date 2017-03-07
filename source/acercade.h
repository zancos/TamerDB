#ifndef ACERCADE_H
#define ACERCADE_H

#include <QDialog>
#include "ui_acercade.h"


namespace Ui {
	class acercadeDialog;
}

class acercadeDialog : public QDialog
{
	Q_OBJECT

public:
	explicit acercadeDialog(QWidget *parent = 0);
	~acercadeDialog();

private:
	Ui::acercadeDialog *ui;

private slots:
	void on_pushButton_close_acercade_clicked();

};


#endif // DIALOG_H
