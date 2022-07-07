/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QPushButton *resume;
    QPushButton *exit;
    QPushButton *restart;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(400, 300);
        resume = new QPushButton(Menu);
        resume->setObjectName(QStringLiteral("resume"));
        resume->setGeometry(QRect(160, 120, 91, 31));
        exit = new QPushButton(Menu);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(160, 220, 91, 31));
        restart = new QPushButton(Menu);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(160, 170, 91, 31));
        restart->setFocusPolicy(Qt::StrongFocus);

        retranslateUi(Menu);
        QObject::connect(restart, SIGNAL(clicked()), Menu, SLOT(accept()));
        QObject::connect(resume, SIGNAL(clicked()), Menu, SLOT(reject()));

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", Q_NULLPTR));
        resume->setText(QApplication::translate("Menu", "Resume", Q_NULLPTR));
        exit->setText(QApplication::translate("Menu", "Exit", Q_NULLPTR));
        restart->setText(QApplication::translate("Menu", "Restart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
