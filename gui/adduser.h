#ifndef ADDUSER_H
#define ADDUSER_H

#include "ui_adduser.h"
#include "mainwindow.h"

class AddUser : public QDialog
{
	Q_OBJECT

	public:
        AddUser(MainWindow *mainWindow);
	public slots:
        void checkCrendentials();
	private:
        Ui_AddUser m_ui;
        MainWindow *m_mainWindow;

};

#endif
