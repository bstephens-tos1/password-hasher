/********************************************************************************
** Form generated from reading UI file 'showhashtable.ui'
**
** Created: Fri Apr 26 15:57:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWHASHTABLE_H
#define UI_SHOWHASHTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QTableWidget *Dump;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(625, 497);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Dump = new QTableWidget(Form);
        Dump->setObjectName(QString::fromUtf8("Dump"));

        gridLayout->addWidget(Dump, 0, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWHASHTABLE_H
