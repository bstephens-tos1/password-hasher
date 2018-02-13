#include "mainwindow.h"
#include "adduser.h"
#include "changepass.h"
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QListWidget>
#include <QMainWindow>
#include <cstdlib>
#include <string>

MainWindow::MainWindow()
{
	m_ui.setupUi(this);

	connect(m_ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(m_ui.actionSave_As, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(m_ui.actionQuit, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));
	m_ui.listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(m_ui.listWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint&)));

	m_contextMenu = new QMenu(this);
	m_actionAddUser = m_contextMenu->addAction("Add User", this, SLOT(addUser()));
	m_contextMenu->addSeparator();
	m_actionAuthenticate = m_contextMenu->addAction("Authenticate", this, SLOT(authenticate()));
	m_actionChangePassword = m_contextMenu->addAction("Change Password", this, SLOT(changePassword()));
	m_actionRemoveUser = m_contextMenu->addAction("Delete", this, SLOT(removeUser()));
}

void MainWindow::addUser()
{
    AddUser dialog(this);
    dialog.exec();
}

void MainWindow::changePassword()
{
    ChangePass dialog(this, m_user);
    dialog.exec();
}

void MainWindow::authenticate()
{

}

void MainWindow::removeUser()
{
    m_hashTable.remove(m_user.toStdString());
    fillUsers();
}

void MainWindow::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = m_ui.listWidget->viewport()->mapToGlobal(pos);

    QListWidgetItem *item = m_ui.listWidget->itemAt(pos);

    if (!item) {
        // disable non-add commands
        m_actionRemoveUser->setEnabled(false);
        m_actionAuthenticate->setEnabled(false);
        m_actionChangePassword->setEnabled(false);

    }
    else {
        m_actionRemoveUser->setEnabled(true);
        m_actionAuthenticate->setEnabled(true);
        m_actionChangePassword->setEnabled(true);

        m_user = item->text();
    }

    m_contextMenu->exec(globalPos);

}

void MainWindow::fillUsers()
{
    // Empty the user list
    while(m_ui.listWidget->count() != 0) {
        m_ui.listWidget->takeItem(0);
    }

    // Generate a list of usernames
    list<string> usernames = m_hashTable.users();

    // Populate the listWidget with the list of usernames
    for (list<string>::iterator itr = usernames.begin(); itr != usernames.end(); itr++) {
        m_ui.listWidget->addItem(QString::fromStdString(*itr));
    }

    // Display status bar information
    QString status = QString::number(m_hashTable.size()) + " users in " + QString::number(m_hashTable.buckets()) + " buckets";
    statusBar()->showMessage(status);

}

void MainWindow::openFile()
{
    // show open file dialog
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));

    if(fileName.isNull()) {
        return;
    }

    // call hashtable load function
    m_hashTable.loadFile(fileName.toStdString());

    // Populate the list
    fillUsers();

    // populate hashtable view
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"));

    if(fileName.isNull()) {
        return;
    }

    // call hashtable write function
    m_hashTable.writeFile(fileName.toStdString());
}


int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

	return app.exec();
}
