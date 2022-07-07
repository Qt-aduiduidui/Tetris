/********************************************************************************
** Form generated from reading UI file 'GameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "gamearea.h"
#include "holdarea.h"
#include "nextarea.h"

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    GameArea *widgetGameArea;
    QWidget *widgetBGD;
    NextArea *widgetNextArea;
    QLabel *labelN;
    QWidget *widgetN;
    QWidget *widgetG;
    QWidget *widgetG_2;
    QWidget *widgetN_2;
    QWidget *widgetS;
    QLabel *labelS;
    QWidget *widgetS_2;
    QLabel *labelScore;
    QWidget *widgetH;
    QWidget *widgetH_2;
    QLabel *labelN_2;
    HoldArea *widgetHoldArea;
    QWidget *widgetSp;
    QLabel *labelSp;
    QLabel *labelSpeed;
    QWidget *widgetSp_2;
    QPushButton *Pause;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(666, 800);
        GameWindow->setMinimumSize(QSize(666, 800));
        GameWindow->setMaximumSize(QSize(666, 800));
        GameWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(666, 800));
        centralWidget->setMaximumSize(QSize(666, 800));
        centralWidget->setAutoFillBackground(true);
        centralWidget->setStyleSheet(QStringLiteral(""));
        widgetGameArea = new GameArea(centralWidget);
        widgetGameArea->setObjectName(QStringLiteral("widgetGameArea"));
        widgetGameArea->setGeometry(QRect(70, 50, 350, 700));
        widgetBGD = new QWidget(centralWidget);
        widgetBGD->setObjectName(QStringLiteral("widgetBGD"));
        widgetBGD->setGeometry(QRect(0, 0, 666, 800));
        widgetBGD->setMinimumSize(QSize(666, 800));
        widgetBGD->setMaximumSize(QSize(666, 800));
        widgetBGD->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/bg.jpg);"));
        widgetNextArea = new NextArea(centralWidget);
        widgetNextArea->setObjectName(QStringLiteral("widgetNextArea"));
        widgetNextArea->setGeometry(QRect(450, 120, 170, 100));
        labelN = new QLabel(centralWidget);
        labelN->setObjectName(QStringLiteral("labelN"));
        labelN->setGeometry(QRect(470, 60, 130, 40));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        labelN->setFont(font);
        labelN->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelN->setAlignment(Qt::AlignCenter);
        widgetN = new QWidget(centralWidget);
        widgetN->setObjectName(QStringLiteral("widgetN"));
        widgetN->setGeometry(QRect(440, 40, 190, 200));
        widgetG = new QWidget(centralWidget);
        widgetG->setObjectName(QStringLiteral("widgetG"));
        widgetG->setGeometry(QRect(60, 40, 370, 720));
        widgetG_2 = new QWidget(centralWidget);
        widgetG_2->setObjectName(QStringLiteral("widgetG_2"));
        widgetG_2->setGeometry(QRect(70, 50, 350, 700));
        widgetN_2 = new QWidget(centralWidget);
        widgetN_2->setObjectName(QStringLiteral("widgetN_2"));
        widgetN_2->setGeometry(QRect(450, 120, 170, 100));
        widgetS = new QWidget(centralWidget);
        widgetS->setObjectName(QStringLiteral("widgetS"));
        widgetS->setGeometry(QRect(440, 430, 190, 130));
        labelS = new QLabel(centralWidget);
        labelS->setObjectName(QStringLiteral("labelS"));
        labelS->setGeometry(QRect(470, 440, 130, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        labelS->setFont(font1);
        labelS->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelS->setAlignment(Qt::AlignCenter);
        widgetS_2 = new QWidget(centralWidget);
        widgetS_2->setObjectName(QStringLiteral("widgetS_2"));
        widgetS_2->setGeometry(QRect(450, 480, 170, 70));
        labelScore = new QLabel(centralWidget);
        labelScore->setObjectName(QStringLiteral("labelScore"));
        labelScore->setEnabled(true);
        labelScore->setGeometry(QRect(450, 480, 170, 70));
        labelScore->setFont(font1);
        labelScore->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelScore->setAlignment(Qt::AlignCenter);
        widgetH = new QWidget(centralWidget);
        widgetH->setObjectName(QStringLiteral("widgetH"));
        widgetH->setGeometry(QRect(440, 250, 190, 170));
        widgetH_2 = new QWidget(centralWidget);
        widgetH_2->setObjectName(QStringLiteral("widgetH_2"));
        widgetH_2->setGeometry(QRect(450, 310, 170, 100));
        labelN_2 = new QLabel(centralWidget);
        labelN_2->setObjectName(QStringLiteral("labelN_2"));
        labelN_2->setGeometry(QRect(470, 260, 130, 40));
        labelN_2->setFont(font1);
        labelN_2->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelN_2->setAlignment(Qt::AlignCenter);
        widgetHoldArea = new HoldArea(centralWidget);
        widgetHoldArea->setObjectName(QStringLiteral("widgetHoldArea"));
        widgetHoldArea->setGeometry(QRect(450, 310, 170, 100));
        widgetSp = new QWidget(centralWidget);
        widgetSp->setObjectName(QStringLiteral("widgetSp"));
        widgetSp->setGeometry(QRect(440, 570, 190, 130));
        widgetSp->setStyleSheet(QStringLiteral("background-color:rgba(247,247,247,0.5);border-radius:15px;"));
        labelSp = new QLabel(centralWidget);
        labelSp->setObjectName(QStringLiteral("labelSp"));
        labelSp->setGeometry(QRect(470, 580, 130, 40));
        labelSp->setFont(font1);
        labelSp->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelSp->setAlignment(Qt::AlignCenter);
        labelSpeed = new QLabel(centralWidget);
        labelSpeed->setObjectName(QStringLiteral("labelSpeed"));
        labelSpeed->setEnabled(true);
        labelSpeed->setGeometry(QRect(450, 620, 170, 70));
        labelSpeed->setFont(font1);
        labelSpeed->setStyleSheet(QStringLiteral("color: rgb(247, 247, 247);"));
        labelSpeed->setAlignment(Qt::AlignCenter);
        widgetSp_2 = new QWidget(centralWidget);
        widgetSp_2->setObjectName(QStringLiteral("widgetSp_2"));
        widgetSp_2->setGeometry(QRect(450, 620, 170, 70));
        Pause = new QPushButton(centralWidget);
        Pause->setObjectName(QStringLiteral("Pause"));
        Pause->setGeometry(QRect(480, 720, 110, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        Pause->setFont(font2);
        Pause->setFocusPolicy(Qt::NoFocus);
        Pause->setStyleSheet(QStringLiteral("background-color:rgba(247,247,247,0.5);border-radius:15px;"));
        GameWindow->setCentralWidget(centralWidget);
        widgetBGD->raise();
        labelN->raise();
        widgetN->raise();
        widgetG->raise();
        widgetG_2->raise();
        widgetGameArea->raise();
        widgetN_2->raise();
        widgetNextArea->raise();
        widgetS->raise();
        labelS->raise();
        widgetS_2->raise();
        labelScore->raise();
        widgetH->raise();
        widgetH_2->raise();
        labelN_2->raise();
        widgetHoldArea->raise();
        widgetSp->raise();
        labelSp->raise();
        widgetSp_2->raise();
        labelSpeed->raise();
        Pause->raise();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", Q_NULLPTR));
        labelN->setText(QApplication::translate("GameWindow", "NEXT", Q_NULLPTR));
        labelS->setText(QApplication::translate("GameWindow", "SCORE", Q_NULLPTR));
        labelScore->setText(QApplication::translate("GameWindow", "0", Q_NULLPTR));
        labelN_2->setText(QApplication::translate("GameWindow", "HOLD", Q_NULLPTR));
        labelSp->setText(QApplication::translate("GameWindow", "SPEED", Q_NULLPTR));
        labelSpeed->setText(QApplication::translate("GameWindow", "1", Q_NULLPTR));
        Pause->setText(QApplication::translate("GameWindow", "Pause", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
