#include "changepass.h"
#include <QMessageBox>

ChangePass::ChangePass(MainWindow *mainWindow, QString username):
  QDialog(mainWindow),
  m_mainWindow(mainWindow),
  m_username(username)
{
    m_ui.setupUi(this);
    connect(m_ui.buttonBox, SIGNAL(accepted()), this, SLOT(checkCrendentials()));
    m_ui.username->setText(username);
}

void ChangePass::checkCrendentials()
{
    if (m_ui.newpass->text() != m_ui.newpass2->text()) {
        QMessageBox::critical(this, "Unmatched Passwords", "The entered passwords do not match.");
        return;
    }

    if (!m_mainWindow->hashtable().changePassword(std::pair<string, string>(m_ui.username->text().toStdString(), m_ui.oldpass->text().toStdString()), m_ui.newpass->text().toStdString())) {
        QMessageBox::critical(this, "Username In Use", "The old password is not correct.");
        return;
    }

    m_mainWindow->fillUsers();

    accept();
}
