/********************************************************************************
** Form generated from reading UI file 'authenticate.ui'
**
** Created: Fri Apr 26 23:11:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATE_H
#define UI_AUTHENTICATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Authenticate
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *password;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Authenticate)
    {
        if (Authenticate->objectName().isEmpty())
            Authenticate->setObjectName(QString::fromUtf8("Authenticate"));
        Authenticate->resize(452, 148);
        verticalLayout = new QVBoxLayout(Authenticate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Authenticate);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        username = new QLineEdit(groupBox);
        username->setObjectName(QString::fromUtf8("username"));

        formLayout->setWidget(0, QFormLayout::FieldRole, username);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));

        formLayout->setWidget(1, QFormLayout::FieldRole, password);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(Authenticate);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, buttonBox);

        retranslateUi(Authenticate);
        QObject::connect(buttonBox, SIGNAL(rejected()), Authenticate, SLOT(reject()));

        QMetaObject::connectSlotsByName(Authenticate);
    } // setupUi

    void retranslateUi(QDialog *Authenticate)
    {
        Authenticate->setWindowTitle(QApplication::translate("Authenticate", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Authenticate", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Authenticate", "Username:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Authenticate", "Password:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Authenticate: public Ui_Authenticate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATE_H
