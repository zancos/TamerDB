#include "settings.h"

static QSettings* settingsPtr = 0;

QSettings* settings()
{
/*
	if (!settingsPtr){
		settingsPtr = new QSettings(QApplication::instance());
		ensureContains();
	}
*/
	return settingsPtr;
}

static void ensureContains()
{

}

void resetDeafaultSettings()
{
	settings()->clear();
	ensureContains();
}
/*
QSetting SettingFile
*/