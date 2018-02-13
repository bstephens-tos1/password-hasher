/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created: Fri Apr 26 23:11:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

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

class Ui_AddUser
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *label_3;
    QLineEdit *password2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QString::fromUtf8("AddUser"));
        AddUser->resize(455, 301);
        verticalLayout = new QVBoxLayout(AddUser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(AddUser);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
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
        password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, password);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        password2 = new QLineEdit(groupBox);
        password2->setObjectName(QString::fromUtf8("password2"));
        password2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, password2);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(AddUser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(username, password);
        QWidget::setTabOrder(password, password2);

        retranslateUi(AddUser);
        QObject::connect(buttonBox, SIGNAL(rejected()), AddUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QDialog *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddUser", "User", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddUser", "Username:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddUser", "Password:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddUser", "Password (Confirm): ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
