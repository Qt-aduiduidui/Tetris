/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *start;
    QPushButton *help;
    QPushButton *record;
    QPushButton *pushButton;
    QTextBrowser *back;
    QLabel *Title;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(600, 800);
        Widget->setStyleSheet(QString::fromUtf8("#back\n"
"{border-image:url(:/new/prefix1/pic/111.jpg)\357\274\233}"));
        start = new QPushButton(Widget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(225, 210, 150, 40));
        help = new QPushButton(Widget);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(225, 350, 150, 40));
        record = new QPushButton(Widget);
        record->setObjectName(QStringLiteral("record"));
        record->setGeometry(QRect(225, 489, 150, 40));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(225, 630, 150, 40));
        back = new QTextBrowser(Widget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(0, 0, 600, 800));
        Title = new QLabel(Widget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(160, 60, 281, 91));
        back->raise();
        start->raise();
        help->raise();
        record->raise();
        pushButton->raise();
        Title->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        start->setText(QApplication::translate("Widget", "Start", Q_NULLPTR));
        help->setText(QApplication::translate("Widget", "Assistantance", Q_NULLPTR));
        record->setText(QApplication::translate("Widget", "Record", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "Exit", Q_NULLPTR));
        Title->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
