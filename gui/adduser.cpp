#include "adduser.h"
#include <QMessageBox>

AddUser::AddUser(MainWindow *mainWindow):
  QDialog(mainWindow),
  m_mainWindow(mainWindow)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, SIGNAL(accepted()), this, SLOT(checkCrendentials()));
}

void AddUser::checkCrendentials()
{
    if (m_ui.password->text() != m_ui.password2->text()) {
        QMessageBox::critical(this, "Unmatched Passwords", "The entered passwords do not match.");
        return;
    }

    if (!m_mainWindow->hashtable().addUser(std::pair<string, string>(m_ui.username->text().toStdString(), m_ui.password->text().toStdString()))) {
        QMessageBox::critical(this, "Username In Use", "The username entered is already in use.");
        return;
    }

    m_mainWindow->fillUsers();

    accept();
}
