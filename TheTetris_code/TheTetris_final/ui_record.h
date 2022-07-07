/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Record
{
public:
    QTextBrowser *textBrowser;
    QTextBrowser *r1;
    QTextBrowser *r2;
    QTextBrowser *r3;
    QTextBrowser *r4;
    QPushButton *pushButton;

    void setupUi(QDialog *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QStringLiteral("Record"));
        Record->resize(400, 300);
        Record->setStyleSheet(QStringLiteral("#Record{border-image:url(:/new/prefix1/pic/3.jpg);}"));
        textBrowser = new QTextBrowser(Record);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(50, 10, 300, 100));
        textBrowser->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);border-width:0;background:transparent;border-style:ourset;"));
        r1 = new QTextBrowser(Record);
        r1->setObjectName(QStringLiteral("r1"));
        r1->setGeometry(QRect(150, 70, 100, 50));
        r1->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        r2 = new QTextBrowser(Record);
        r2->setObjectName(QStringLiteral("r2"));
        r2->setGeometry(QRect(150, 120, 100, 50));
        r2->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        r3 = new QTextBrowser(Record);
        r3->setObjectName(QStringLiteral("r3"));
        r3->setGeometry(QRect(150, 170, 100, 50));
        r3->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        r4 = new QTextBrowser(Record);
        r4->setObjectName(QStringLiteral("r4"));
        r4->setGeometry(QRect(150, 220, 100, 50));
        r4->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        pushButton = new QPushButton(Record);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 250, 91, 31));

        retranslateUi(Record);

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QDialog *Record)
    {
        Record->setWindowTitle(QApplication::translate("Record", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Record", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">Glory Record</span></p></body></html>", Q_NULLPTR));
        r1->setHtml(QApplication::translate("Record", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">100</span></p></body></html>", Q_NULLPTR));
        r2->setHtml(QApplication::translate("Record", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">90</span></p></body></html>", Q_NULLPTR));
        r3->setHtml(QApplication::translate("Record", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">80</span></p></body></html>", Q_NULLPTR));
        r4->setHtml(QApplication::translate("Record", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">70</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Record", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
