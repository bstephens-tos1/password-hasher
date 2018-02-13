#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "../hashtable.h"
#include <QMenu>
#include <QAction>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
        MainWindow();
        void fillUsers();
        cop4530::HashTable &hashtable() { return m_hashTable; }

	public slots:
        void openFile();
        void saveFile();
        void showContextMenu(const QPoint&);
        void addUser();
        void changePassword();
        void removeUser();
        void authenticate();

	private:
        Ui_MainWindow m_ui;
        cop4530::HashTable m_hashTable;
        QMenu* m_contextMenu;
        QAction* m_actionAddUser;
        QAction* m_actionRemoveUser;
        QAction* m_actionChangePassword;
        QAction* m_actionAuthenticate;
        QString m_user;
};

#endif
