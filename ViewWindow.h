/********************************************************************************
** Form generated from reading UI file 'FinancialManagerCO8028.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINANCIALMANAGERCO8028_H
#define FINANCIALMANAGERCO8028_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
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
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QFrame *line_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_sendMoney;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_receiveMoney;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_4;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_payerName;
    QLabel *label_12;
    QLineEdit *lineEdit_payerIBAN;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_beneficiaryName;
    QLabel *label_13;
    QLineEdit *lineEdit_beneficiaryIBAN;
    QLineEdit *lineEdit_amount;
    QLabel *label_17;
    QLineEdit *lineEdit_causal;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_currentDate;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_doTransaction;
    QPushButton *pushButton_Cancel;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QScrollBar *verticalScrollBar;
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
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        sizePolicy.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(15);
        groupBox->setFont(font1);
        horizontalLayout_7 = new QHBoxLayout(groupBox);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        radioButton_sendMoney = new QRadioButton(groupBox);
        radioButton_sendMoney->setObjectName(QStringLiteral("radioButton_sendMoney"));
        radioButton_sendMoney->setChecked(true);

        horizontalLayout_7->addWidget(radioButton_sendMoney);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        radioButton_receiveMoney = new QRadioButton(groupBox);
        radioButton_receiveMoney->setObjectName(QStringLiteral("radioButton_receiveMoney"));

        horizontalLayout_7->addWidget(radioButton_receiveMoney);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox);

        line_4 = new QFrame(tab_3);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font2;
        font2.setPointSize(18);
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_10);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_11);

        lineEdit_payerName = new QLineEdit(tab_3);
        lineEdit_payerName->setObjectName(QStringLiteral("lineEdit_payerName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_payerName);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_12);

        lineEdit_payerIBAN = new QLineEdit(tab_3);
        lineEdit_payerIBAN->setObjectName(QStringLiteral("lineEdit_payerIBAN"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_payerIBAN);

        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font3;
        font3.setPointSize(17);
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, label_14);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_15);

        lineEdit_beneficiaryName = new QLineEdit(tab_3);
        lineEdit_beneficiaryName->setObjectName(QStringLiteral("lineEdit_beneficiaryName"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_beneficiaryName);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_13);

        lineEdit_beneficiaryIBAN = new QLineEdit(tab_3);
        lineEdit_beneficiaryIBAN->setObjectName(QStringLiteral("lineEdit_beneficiaryIBAN"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_beneficiaryIBAN);

        lineEdit_amount = new QLineEdit(tab_3);
        lineEdit_amount->setObjectName(QStringLiteral("lineEdit_amount"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_amount);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_17);

        lineEdit_causal = new QLineEdit(tab_3);
        lineEdit_causal->setObjectName(QStringLiteral("lineEdit_causal"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_causal);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_16);

        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_18);

        label_currentDate = new QLabel(tab_3);
        label_currentDate->setObjectName(QStringLiteral("label_currentDate"));

        formLayout->setWidget(8, QFormLayout::FieldRole, label_currentDate);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_doTransaction = new QPushButton(tab_3);
        pushButton_doTransaction->setObjectName(QStringLiteral("pushButton_doTransaction"));

        horizontalLayout_10->addWidget(pushButton_doTransaction);

        pushButton_Cancel = new QPushButton(tab_3);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_10->addWidget(pushButton_Cancel);


        verticalLayout_2->addLayout(horizontalLayout_10);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_19);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        horizontalLayout_8->addLayout(verticalLayout_5);

        verticalScrollBar = new QScrollBar(tab_4);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalScrollBar->setInvertedAppearance(false);

        horizontalLayout_8->addWidget(verticalScrollBar);


        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_4, QString());
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

        tabWidget->setCurrentIndex(2);


        //---------------------------------------

        horizontalWidget_title->hide();



        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(closeApp()));
        QObject::connect(actionRESET, SIGNAL(triggered()), MainWindow, SLOT(RESET()));
        QObject::connect(Button_Salva, SIGNAL(clicked()), MainWindow, SLOT(accountSave()));
        QObject::connect(toolButton, SIGNAL(clicked()), MainWindow, SLOT(showTitleEdit()));
        QObject::connect(buttonTitle_Salva, SIGNAL(clicked()), MainWindow, SLOT (contoTitleSave()));
        QObject::connect(radioButton_sendMoney, SIGNAL (released()), MainWindow, SLOT(radioButtonClicked()));
        QObject::connect(radioButton_receiveMoney, SIGNAL (released()), MainWindow, SLOT(radioButtonClicked()));
        QObject::connect(pushButton_doTransaction, SIGNAL(clicked()), MainWindow, SLOT(doTransaction()));


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
        label_8->setText(QApplication::translate("MainWindow", "Effettua una transazione", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Tipo di transazione", Q_NULLPTR));
        radioButton_sendMoney->setText(QApplication::translate("MainWindow", "Invia denaro", Q_NULLPTR));
        radioButton_receiveMoney->setText(QApplication::translate("MainWindow", "Ricevi denaro", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Dati dell'ordinante:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Nome e cognome:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "IBAN: ", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Dati del Beneficiario:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Nome e Cognome: ", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "IBAN:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Causale: ", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Importo: ", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Data: ", Q_NULLPTR));
        label_currentDate->setText(QApplication::translate("MainWindow", "01/01/01", Q_NULLPTR));
        pushButton_doTransaction->setText(QApplication::translate("MainWindow", "Esegui", Q_NULLPTR));
        pushButton_Cancel->setText(QApplication::translate("MainWindow", "Annulla", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Effettua Transazioni", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "STORICO TRANSAZIONI", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Storico", Q_NULLPTR));
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

#endif // FINANCIALMANAGERCO8028_H
