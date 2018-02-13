#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include "ui_changepass.h"
#include "mainwindow.h"
#include <QString>

class ChangePass : public QDialog
{
	Q_OBJECT

	public:
        ChangePass(MainWindow *mainWindow, QString);
	public slots:
        void checkCrendentials();
	private:
        Ui_ChangePassword m_ui;
        MainWindow *m_mainWindow;
        QString m_username;

};

#endif
