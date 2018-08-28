/********************************************************************************
** Form generated from reading UI file 'investmentFormdI1755.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INVESTMENTFORMDI1755_H
#define INVESTMENTFORMDI1755_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_investmentForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_investmentType;
    QLabel *label_2;
    QLabel *label_entityName;
    QLabel *label_3;
    QLabel *label_entityISIN;
    QLabel *label_4;
    QLabel *label_buyDate;
    QLabel *label_8;
    QLabel *label_totalInvestment;
    QWidget *formWidget_stockData;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_stockShareNumber;
    QLabel *label_stockShareCost;
    QLabel *label_stockActualInvestment;
    QWidget *formWidget_bondData;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_bondMonthsNumber;
    QLabel *label_deadlineDate;
    QLabel *label_bondCoupon;
    QLabel *label_bondExpectedYield;
    QWidget *formWidget_fundData;
    QFormLayout *formLayout_4;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_fundShareNumber;
    QLabel *label_fundShareCost;
    QLabel *label_fundComposition;
    QLabel *label_fundActualInvestment;
    QPushButton *pushButton_sell;
    QFrame *line;

    void setupUi(QWidget *investmentForm)
    {
        if (investmentForm->objectName().isEmpty())
            investmentForm->setObjectName(QStringLiteral("investmentForm"));
        investmentForm->resize(762, 512);
        horizontalLayout = new QHBoxLayout(investmentForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(investmentForm);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_investmentType = new QLabel(widget);
        label_investmentType->setObjectName(QStringLiteral("label_investmentType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_investmentType);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_entityName = new QLabel(widget);
        label_entityName->setObjectName(QStringLiteral("label_entityName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_entityName);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_entityISIN = new QLabel(widget);
        label_entityISIN->setObjectName(QStringLiteral("label_entityISIN"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_entityISIN);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_buyDate = new QLabel(widget);
        label_buyDate->setObjectName(QStringLiteral("label_buyDate"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_buyDate);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        label_totalInvestment = new QLabel(widget);
        label_totalInvestment->setObjectName(QStringLiteral("label_totalInvestment"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_totalInvestment);


        verticalLayout->addWidget(widget);

        formWidget_stockData = new QWidget(investmentForm);
        formWidget_stockData->setObjectName(QStringLiteral("formWidget_stockData"));
        sizePolicy.setHeightForWidth(formWidget_stockData->sizePolicy().hasHeightForWidth());
        formWidget_stockData->setSizePolicy(sizePolicy);
        formLayout_2 = new QFormLayout(formWidget_stockData);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label_5 = new QLabel(formWidget_stockData);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formWidget_stockData);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formWidget_stockData);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        label_stockShareNumber = new QLabel(formWidget_stockData);
        label_stockShareNumber->setObjectName(QStringLiteral("label_stockShareNumber"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_stockShareNumber);

        label_stockShareCost = new QLabel(formWidget_stockData);
        label_stockShareCost->setObjectName(QStringLiteral("label_stockShareCost"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_stockShareCost);

        label_stockActualInvestment = new QLabel(formWidget_stockData);
        label_stockActualInvestment->setObjectName(QStringLiteral("label_stockActualInvestment"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, label_stockActualInvestment);


        verticalLayout->addWidget(formWidget_stockData);

        formWidget_bondData = new QWidget(investmentForm);
        formWidget_bondData->setObjectName(QStringLiteral("formWidget_bondData"));
        sizePolicy.setHeightForWidth(formWidget_bondData->sizePolicy().hasHeightForWidth());
        formWidget_bondData->setSizePolicy(sizePolicy);
        formLayout_3 = new QFormLayout(formWidget_bondData);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_9 = new QLabel(formWidget_bondData);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formWidget_bondData);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formWidget_bondData);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formWidget_bondData);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_12);

        label_bondMonthsNumber = new QLabel(formWidget_bondData);
        label_bondMonthsNumber->setObjectName(QStringLiteral("label_bondMonthsNumber"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_bondMonthsNumber);

        label_deadlineDate = new QLabel(formWidget_bondData);
        label_deadlineDate->setObjectName(QStringLiteral("label_deadlineDate"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_deadlineDate);

        label_bondCoupon = new QLabel(formWidget_bondData);
        label_bondCoupon->setObjectName(QStringLiteral("label_bondCoupon"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, label_bondCoupon);

        label_bondExpectedYield = new QLabel(formWidget_bondData);
        label_bondExpectedYield->setObjectName(QStringLiteral("label_bondExpectedYield"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, label_bondExpectedYield);


        verticalLayout->addWidget(formWidget_bondData);

        formWidget_fundData = new QWidget(investmentForm);
        formWidget_fundData->setObjectName(QStringLiteral("formWidget_fundData"));
        sizePolicy.setHeightForWidth(formWidget_fundData->sizePolicy().hasHeightForWidth());
        formWidget_fundData->setSizePolicy(sizePolicy);
        formLayout_4 = new QFormLayout(formWidget_fundData);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_13 = new QLabel(formWidget_fundData);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(formWidget_fundData);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formWidget_fundData);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(formWidget_fundData);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_16);

        label_fundShareNumber = new QLabel(formWidget_fundData);
        label_fundShareNumber->setObjectName(QStringLiteral("label_fundShareNumber"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, label_fundShareNumber);

        label_fundShareCost = new QLabel(formWidget_fundData);
        label_fundShareCost->setObjectName(QStringLiteral("label_fundShareCost"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, label_fundShareCost);

        label_fundComposition = new QLabel(formWidget_fundData);
        label_fundComposition->setObjectName(QStringLiteral("label_fundComposition"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, label_fundComposition);

        label_fundActualInvestment = new QLabel(formWidget_fundData);
        label_fundActualInvestment->setObjectName(QStringLiteral("label_fundActualInvestment"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, label_fundActualInvestment);


        verticalLayout->addWidget(formWidget_fundData);

        pushButton_sell = new QPushButton(investmentForm);
        pushButton_sell->setObjectName(QStringLiteral("pushButton_sell"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_sell->sizePolicy().hasHeightForWidth());
        pushButton_sell->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_sell);

        line = new QFrame(investmentForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(investmentForm);


        //---------------------------------

        formWidget_stockData->hide();
        formWidget_bondData->hide();
        formWidget_fundData->hide();

        pushButton_sell->hide();





        //------------------------------------

        QMetaObject::connectSlotsByName(investmentForm);
    } // setupUi

    void retranslateUi(QWidget *investmentForm)
    {
        investmentForm->setWindowTitle(QApplication::translate("investmentForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("investmentForm", "Tipologia: ", Q_NULLPTR));
        label_investmentType->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_2->setText(QApplication::translate("investmentForm", "Nome della societ\303\240: ", Q_NULLPTR));
        label_entityName->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_3->setText(QApplication::translate("investmentForm", "ISIN della societ\303\240: ", Q_NULLPTR));
        label_entityISIN->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_4->setText(QApplication::translate("investmentForm", "Data di acquisto: ", Q_NULLPTR));
        label_buyDate->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_8->setText(QApplication::translate("investmentForm", "Investimento totale: ", Q_NULLPTR));
        label_totalInvestment->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_5->setText(QApplication::translate("investmentForm", "Numero di azioni: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("investmentForm", "Prezzo delle azioni: ", Q_NULLPTR));
        label_7->setText(QApplication::translate("investmentForm", "Valore attuale: ", Q_NULLPTR));
        label_stockShareNumber->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_stockShareCost->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_stockActualInvestment->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_9->setText(QApplication::translate("investmentForm", "Orizzonte temporale (mesi) : ", Q_NULLPTR));
        label_10->setText(QApplication::translate("investmentForm", "Data di scadenza: ", Q_NULLPTR));
        label_11->setText(QApplication::translate("investmentForm", "Rendimento previsto: ", Q_NULLPTR));
        label_12->setText(QApplication::translate("investmentForm", "Cedola: ", Q_NULLPTR));
        label_bondMonthsNumber->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_deadlineDate->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_bondCoupon->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_bondExpectedYield->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_13->setText(QApplication::translate("investmentForm", "Numero di quote: ", Q_NULLPTR));
        label_14->setText(QApplication::translate("investmentForm", "Prezzo delle quote: ", Q_NULLPTR));
        label_15->setText(QApplication::translate("investmentForm", "Composizione: ", Q_NULLPTR));
        label_16->setText(QApplication::translate("investmentForm", "Valore attuale: ", Q_NULLPTR));
        label_fundShareNumber->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_fundShareCost->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_fundComposition->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        label_fundActualInvestment->setText(QApplication::translate("investmentForm", "---", Q_NULLPTR));
        pushButton_sell->setText(QApplication::translate("investmentForm", "Vendi", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class investmentForm: public Ui_investmentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INVESTMENTFORMDI1755_H
