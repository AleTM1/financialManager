/********************************************************************************
** Form generated from reading UI file 'FinancialManagerHV2176.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINANCIALMANAGERHV2176_H
#define FINANCIALMANAGERHV2176_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qsliderreadonly.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRESET;
    QAction *actionClose;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_title;
    QToolButton *toolButton;
    QWidget *horizontalWidget_title;
    QHBoxLayout *horizontalLayout_titleEdit;
    QLineEdit *lineEdit_title;
    QPushButton *buttonTitle_Salva;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_IBAN;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *label_Saldo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_liquid;
    QSliderReadOnly *horizontalSlider_percetage;
    QLabel *label_invested;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QTextEdit *textEdit_Mail;
    QTextEdit *textEdit_PhoneNumber;
    QTextEdit *textEdit_Name;
    QTextEdit *textEdit_Address;
    QTextEdit *textEdit_Surname;
    QTextEdit *textEdit_city;
    QLabel *label_3;
    QLabel *label;
    QTextEdit *textEdit_CAP;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button_Salva;
    QPushButton *Button_annulla;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(914, 650);
        actionRESET = new QAction(MainWindow);
        actionRESET->setObjectName(QStringLiteral("actionRESET"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_title = new QLabel(tab);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setPointSize(20);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_title);

        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout_2->addWidget(toolButton);

        horizontalWidget_title = new QWidget(tab);
        horizontalWidget_title->setObjectName(QStringLiteral("horizontalWidget_title"));
        horizontalLayout_titleEdit = new QHBoxLayout(horizontalWidget_title);
        horizontalLayout_titleEdit->setObjectName(QStringLiteral("horizontalLayout_titleEdit"));
        lineEdit_title = new QLineEdit(horizontalWidget_title);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));

        horizontalLayout_titleEdit->addWidget(lineEdit_title);

        buttonTitle_Salva = new QPushButton(horizontalWidget_title);
        buttonTitle_Salva->setObjectName(QStringLiteral("buttonTitle_Salva"));

        horizontalLayout_titleEdit->addWidget(buttonTitle_Salva);


        horizontalLayout_2->addWidget(horizontalWidget_title);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_IBAN = new QLabel(tab);
        label_IBAN->setObjectName(QStringLiteral("label_IBAN"));
        label_IBAN->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_IBAN);


        verticalLayout->addLayout(horizontalLayout_4);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_9);

        label_Saldo = new QLabel(tab);
        label_Saldo->setObjectName(QStringLiteral("label_Saldo"));

        horizontalLayout_5->addWidget(label_Saldo);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_liquid = new QLabel(tab);
        label_liquid->setObjectName(QStringLiteral("label_liquid"));

        horizontalLayout_6->addWidget(label_liquid);

        horizontalSlider_percetage = new QSliderReadOnly(tab);
        horizontalSlider_percetage->setObjectName(QStringLiteral("horizontalSlider_percetage"));
        horizontalSlider_percetage->setEnabled(true);
        horizontalSlider_percetage->setMaximum(100);
        horizontalSlider_percetage->setValue(50);
        horizontalSlider_percetage->setTracking(true);
        horizontalSlider_percetage->setOrientation(Qt::Horizontal);
        horizontalSlider_percetage->setTickPosition(QSlider::NoTicks);

        horizontalLayout_6->addWidget(horizontalSlider_percetage);

        label_invested = new QLabel(tab);
        label_invested->setObjectName(QStringLiteral("label_invested"));

        horizontalLayout_6->addWidget(label_invested);


        verticalLayout->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        textEdit_Mail = new QTextEdit(tab_2);
        textEdit_Mail->setObjectName(QStringLiteral("textEdit_Mail"));

        gridLayout->addWidget(textEdit_Mail, 6, 2, 1, 1);

        textEdit_PhoneNumber = new QTextEdit(tab_2);
        textEdit_PhoneNumber->setObjectName(QStringLiteral("textEdit_PhoneNumber"));

        gridLayout->addWidget(textEdit_PhoneNumber, 5, 2, 1, 1);

        textEdit_Name = new QTextEdit(tab_2);
        textEdit_Name->setObjectName(QStringLiteral("textEdit_Name"));

        gridLayout->addWidget(textEdit_Name, 0, 2, 1, 1);

        textEdit_Address = new QTextEdit(tab_2);
        textEdit_Address->setObjectName(QStringLiteral("textEdit_Address"));

        gridLayout->addWidget(textEdit_Address, 4, 2, 1, 1);

        textEdit_Surname = new QTextEdit(tab_2);
        textEdit_Surname->setObjectName(QStringLiteral("textEdit_Surname"));

        gridLayout->addWidget(textEdit_Surname, 1, 2, 1, 1);

        textEdit_city = new QTextEdit(tab_2);
        textEdit_city->setObjectName(QStringLiteral("textEdit_city"));

        gridLayout->addWidget(textEdit_city, 2, 2, 1, 1);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit_CAP = new QTextEdit(tab_2);
        textEdit_CAP->setObjectName(QStringLiteral("textEdit_CAP"));

        gridLayout->addWidget(textEdit_CAP, 3, 2, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Button_Salva = new QPushButton(tab_2);
        Button_Salva->setObjectName(QStringLiteral("Button_Salva"));

        horizontalLayout_3->addWidget(Button_Salva);

        Button_annulla = new QPushButton(tab_2);
        Button_annulla->setObjectName(QStringLiteral("Button_annulla"));

        horizontalLayout_3->addWidget(Button_annulla);


        gridLayout->addLayout(horizontalLayout_3, 7, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 914, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionRESET);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);



        //---------------------------------------

        horizontalWidget_title->hide();



        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(closeApp()));
        QObject::connect(actionRESET, SIGNAL(triggered()), MainWindow, SLOT(RESET()));
        QObject::connect(Button_Salva, SIGNAL(clicked()), MainWindow, SLOT(accountSave()));
        QObject::connect(toolButton, SIGNAL(clicked()), MainWindow, SLOT(showTitleEdit()));
        QObject::connect(buttonTitle_Salva, SIGNAL(clicked()), MainWindow, SLOT (contoTitleSave()));


        //---------------------------------------------------------------------------



        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionRESET->setText(QApplication::translate("MainWindow", "RESET", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        label_title->setText(QApplication::translate("MainWindow", "----", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        buttonTitle_Salva->setText(QApplication::translate("MainWindow", "Salva modifiche", Q_NULLPTR));
        label_IBAN->setText(QApplication::translate("MainWindow", "IBAN: ", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Saldo Complessivo:", Q_NULLPTR));
        label_Saldo->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_liquid->setText(QApplication::translate("MainWindow", " Liquidit\303\240:", Q_NULLPTR));
        label_invested->setText(QApplication::translate("MainWindow", " Investito: ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Sintesi", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Cognome:", Q_NULLPTR));
        textEdit_Name->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                                     "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                                                                     "p, li { white-space: pre-wrap; }\n"
                                                                     "</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
                                                                     "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Citt\303\240: ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nome: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Telefono: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "CAP: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Indirizzo: ", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Mail: ", Q_NULLPTR));
        Button_Salva->setText(QApplication::translate("MainWindow", "Salva", Q_NULLPTR));
        Button_annulla->setText(QApplication::translate("MainWindow", "Annulla", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Account", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FINANCIALMANAGERHV2176_H
