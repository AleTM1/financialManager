//
// Created by alessandro on 18/08/18.
//

#ifndef FINANCIALMANAGER_TRANSACTIONFORMUI_H
#define FINANCIALMANAGER_TRANSACTIONFORMUI_H

/********************************************************************************
** Form generated from reading UI file 'transactionFormIv8028.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRANSACTIONFORMIV8028_H
#define TRANSACTIONFORMIV8028_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transactionForm
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_date;
    QLabel *label_causal;
    QLabel *label_amount;
    QLabel *label_beneficiaryIBAN;
    QLabel *label_beneficiaryName;
    QLabel *label_payerIBAN;
    QLabel *label_payerName;
    QLabel *label_debit;
    QFrame *line;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(711, 282);
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(Form);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(Form);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(Form);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(Form);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        label_date = new QLabel(Form);
        label_date->setObjectName(QStringLiteral("label_date"));

        formLayout->setWidget(7, QFormLayout::FieldRole, label_date);

        label_causal = new QLabel(Form);
        label_causal->setObjectName(QStringLiteral("label_causal"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_causal);

        label_amount = new QLabel(Form);
        label_amount->setObjectName(QStringLiteral("label_amount"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_amount);

        label_beneficiaryIBAN = new QLabel(Form);
        label_beneficiaryIBAN->setObjectName(QStringLiteral("label_beneficiaryIBAN"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_beneficiaryIBAN);

        label_beneficiaryName = new QLabel(Form);
        label_beneficiaryName->setObjectName(QStringLiteral("label_beneficiaryName"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_beneficiaryName);

        label_payerIBAN = new QLabel(Form);
        label_payerIBAN->setObjectName(QStringLiteral("label_payerIBAN"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_payerIBAN);

        label_payerName = new QLabel(Form);
        label_payerName->setObjectName(QStringLiteral("label_payerName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_payerName);

        label_debit = new QLabel(Form);
        label_debit->setObjectName(QStringLiteral("label_debit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_debit);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "Tipologia: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "Nome dell'ordinante: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "IBAN del'ordinante: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "Nome del beneficiario: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form", "IBAN del beneficiario: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "Importo: ", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", "Causale: ", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form", "Data: ", Q_NULLPTR));
        label_date->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_causal->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_amount->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_beneficiaryIBAN->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_beneficiaryName->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_payerIBAN->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_payerName->setText(QApplication::translate("Form", "---", Q_NULLPTR));
        label_debit->setText(QApplication::translate("Form", "---", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_transactionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRANSACTIONFORMIV8028_H


#endif //FINANCIALMANAGER_TRANSACTIONFORMUI_H
