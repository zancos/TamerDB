#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "ui_configuration.h"
#include <QDialog>

namespace Ui {
	class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ConfigurationDialog(QWidget *parent = 0);
	~ConfigurationDialog();

private:
	Ui::ConfigurationDialog *ui;

private slots:
	void on_pushButton_save_db_config_clicked();
	void pushButton_close_db_config();
};

#endif // DIALOG_H
