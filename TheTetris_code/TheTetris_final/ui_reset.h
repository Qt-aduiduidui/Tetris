/********************************************************************************
** Form generated from reading UI file 'reset.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESET_H
#define UI_RESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Reset
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Reset)
    {
        if (Reset->objectName().isEmpty())
            Reset->setObjectName(QStringLiteral("Reset"));
        Reset->resize(350, 200);
        pushButton = new QPushButton(Reset);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 150, 91, 31));
        pushButton_2 = new QPushButton(Reset);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 150, 91, 31));
        textBrowser = new QTextBrowser(Reset);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 350, 111));
        textBrowser->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);border-width:0;background:transparent;border-style:ourset;"));

        retranslateUi(Reset);

        QMetaObject::connectSlotsByName(Reset);
    } // setupUi

    void retranslateUi(QDialog *Reset)
    {
        Reset->setWindowTitle(QApplication::translate("Reset", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Reset", "yes", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Reset", "no", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Reset", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">\347\241\256\345\256\232\346\270\205\347\251\272\350\256\260\345\275\225\357\274\237</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reset: public Ui_Reset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESET_H
