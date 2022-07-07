/********************************************************************************
** Form generated from reading UI file 'assistant.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSISTANT_H
#define UI_ASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_assistant
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *assistant)
    {
        if (assistant->objectName().isEmpty())
            assistant->setObjectName(QStringLiteral("assistant"));
        assistant->resize(400, 500);
        assistant->setStyleSheet(QStringLiteral("border-image:url(:/new/prefix1/pic/2.jpg)"));
        gridLayout = new QGridLayout(assistant);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser = new QTextBrowser(assistant);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(assistant);

        QMetaObject::connectSlotsByName(assistant);
    } // setupUi

    void retranslateUi(QDialog *assistant)
    {
        assistant->setWindowTitle(QApplication::translate("assistant", "Dialog", Q_NULLPTR));
        textBrowser->setMarkdown(QString());
        textBrowser->setHtml(QApplication::translate("assistant", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class assistant: public Ui_assistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSISTANT_H
