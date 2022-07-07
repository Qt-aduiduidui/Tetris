/********************************************************************************
** Form generated from reading UI file 'exit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXIT_H
#define UI_EXIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Exit
{
public:
    QTextBrowser *text;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QDialog *Exit)
    {
        if (Exit->objectName().isEmpty())
            Exit->setObjectName(QStringLiteral("Exit"));
        Exit->resize(300, 240);
        Exit->setStyleSheet(QStringLiteral("#Exit{border-image:url(:/new/prefix1/pic/4.jpg)}"));
        text = new QTextBrowser(Exit);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(50, 0, 200, 121));
        text->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);border-width:0;background:transparent;border-style:ourset;"));
        yes = new QPushButton(Exit);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setGeometry(QRect(30, 200, 100, 30));
        no = new QPushButton(Exit);
        no->setObjectName(QStringLiteral("no"));
        no->setGeometry(QRect(170, 200, 100, 30));

        retranslateUi(Exit);
        QObject::connect(yes, SIGNAL(clicked()), Exit, SLOT(accept()));

        QMetaObject::connectSlotsByName(Exit);
    } // setupUi

    void retranslateUi(QDialog *Exit)
    {
        Exit->setWindowTitle(QApplication::translate("Exit", "Dialog", Q_NULLPTR));
        text->setHtml(QApplication::translate("Exit", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt; color:#ffaa7f;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffaa7f;\">\347\241\256\345\256\232\347\246\273\345\274\200\357\274\237</span></p></body></html>", Q_NULLPTR));
        yes->setText(QApplication::translate("Exit", "yes", Q_NULLPTR));
        no->setText(QApplication::translate("Exit", "no", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Exit: public Ui_Exit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXIT_H
