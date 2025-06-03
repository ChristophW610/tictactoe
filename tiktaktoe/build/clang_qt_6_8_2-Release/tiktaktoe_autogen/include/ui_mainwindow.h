/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *A2;
    QPushButton *B2;
    QPushButton *C3;
    QPushButton *A1;
    QPushButton *B3;
    QPushButton *C1;
    QPushButton *A3;
    QPushButton *C2;
    QPushButton *B1;
    QLabel *label;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(743, 609);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 10, 211, 51));
        QFont font;
        font.setPointSize(16);
        font.setUnderline(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(490, 80, 241, 51));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 466, 607));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 30);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        A2 = new QPushButton(widget);
        A2->setObjectName(QString::fromUtf8("A2"));
        A2->setMinimumSize(QSize(150, 150));
        A2->setMaximumSize(QSize(150, 150));
        QFont font1;
        font1.setPointSize(26);
        A2->setFont(font1);

        gridLayout->addWidget(A2, 0, 1, 1, 1);

        B2 = new QPushButton(widget);
        B2->setObjectName(QString::fromUtf8("B2"));
        B2->setMinimumSize(QSize(150, 150));
        B2->setMaximumSize(QSize(150, 150));
        B2->setFont(font1);

        gridLayout->addWidget(B2, 1, 1, 1, 1);

        C3 = new QPushButton(widget);
        C3->setObjectName(QString::fromUtf8("C3"));
        C3->setMinimumSize(QSize(150, 150));
        C3->setMaximumSize(QSize(150, 150));
        C3->setFont(font1);

        gridLayout->addWidget(C3, 2, 2, 1, 1);

        A1 = new QPushButton(widget);
        A1->setObjectName(QString::fromUtf8("A1"));
        A1->setMinimumSize(QSize(150, 150));
        A1->setMaximumSize(QSize(150, 150));
        A1->setFont(font1);

        gridLayout->addWidget(A1, 0, 0, 1, 1);

        B3 = new QPushButton(widget);
        B3->setObjectName(QString::fromUtf8("B3"));
        B3->setMinimumSize(QSize(150, 150));
        B3->setMaximumSize(QSize(150, 150));
        B3->setFont(font1);

        gridLayout->addWidget(B3, 1, 2, 1, 1);

        C1 = new QPushButton(widget);
        C1->setObjectName(QString::fromUtf8("C1"));
        C1->setMinimumSize(QSize(150, 150));
        C1->setMaximumSize(QSize(150, 150));
        C1->setFont(font1);

        gridLayout->addWidget(C1, 2, 0, 1, 1);

        A3 = new QPushButton(widget);
        A3->setObjectName(QString::fromUtf8("A3"));
        A3->setMinimumSize(QSize(150, 150));
        A3->setMaximumSize(QSize(150, 150));
        A3->setFont(font1);

        gridLayout->addWidget(A3, 0, 2, 1, 1);

        C2 = new QPushButton(widget);
        C2->setObjectName(QString::fromUtf8("C2"));
        C2->setMinimumSize(QSize(150, 150));
        C2->setMaximumSize(QSize(150, 150));
        C2->setFont(font1);

        gridLayout->addWidget(C2, 2, 1, 1, 1);

        B1 = new QPushButton(widget);
        B1->setObjectName(QString::fromUtf8("B1"));
        B1->setMinimumSize(QSize(150, 150));
        B1->setMaximumSize(QSize(150, 150));
        B1->setFont(font1);

        gridLayout->addWidget(B1, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        resetButton = new QPushButton(widget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setEnabled(true);
        resetButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(resetButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 743, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Schwierigkeitsgrad", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "einfach", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "schwer", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "unm\303\266glich", nullptr));

        A2->setText(QString());
        B2->setText(QString());
        C3->setText(QString());
        A1->setText(QString());
        B3->setText(QString());
        C1->setText(QString());
        A3->setText(QString());
        C2->setText(QString());
        B1->setText(QString());
        label->setText(QString());
        resetButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
