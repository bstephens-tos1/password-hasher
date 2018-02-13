/********************************************************************************
** Form generated from reading UI file 'changepass.ui'
**
** Created: Fri Apr 26 23:47:16 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASS_H
#define UI_CHANGEPASS_H

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

class Ui_ChangePassword
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *username;
    QLabel *label_2;
    QLineEdit *oldpass;
    QLabel *label_3;
    QLineEdit *newpass;
    QLabel *label_4;
    QLineEdit *newpass2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(455, 213);
        verticalLayout = new QVBoxLayout(ChangePassword);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ChangePassword);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        username = new QLineEdit(groupBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, username);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        oldpass = new QLineEdit(groupBox);
        oldpass->setObjectName(QString::fromUtf8("oldpass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, oldpass);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        newpass = new QLineEdit(groupBox);
        newpass->setObjectName(QString::fromUtf8("newpass"));

        formLayout->setWidget(2, QFormLayout::FieldRole, newpass);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        newpass2 = new QLineEdit(groupBox);
        newpass2->setObjectName(QString::fromUtf8("newpass2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, newpass2);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(ChangePassword);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(username, oldpass);
        QWidget::setTabOrder(oldpass, newpass);
        QWidget::setTabOrder(newpass, newpass2);
        QWidget::setTabOrder(newpass2, buttonBox);

        retranslateUi(ChangePassword);
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangePassword, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QDialog *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ChangePassword", "Change Password", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChangePassword", "Username:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChangePassword", "Old Password:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChangePassword", "New Password:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ChangePassword", "New Password (Confirm): ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASS_H
