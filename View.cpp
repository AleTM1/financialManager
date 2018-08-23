//
// Created by alessandro on 07/08/18.
//


#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDate>
#include "View.h"


View::View(Controller *c, Model *m):controller(c), model(m), viewWindow(new Ui_MainWindow) {

    viewWindow->setupUi(this);
    model->addObserver(this);
    controller->openingApp();

}



View::~View() {

    model->removeObserver(this);

    delete viewWindow;
    delete dialogNoButton;

}


void View::update() {

    updateMessages();

    if(model->isTabAccountLocked()){

        lockAccountTab();

    }else {

        auto account = updateAccount();

        auto conto = updateConto();

        updateTransaction(account, conto);

        updateHistorical();

    }

}

void View::lockAccountTab() const {

    viewWindow->lineEdit_nameAccount->setEnabled(true);
    viewWindow->lineEdit_surnameAccount->setEnabled(true);
    viewWindow->lineEdit_codiceFiscaleAccount->setEnabled(true);

    viewWindow->tabWidget->setCurrentIndex(3);

    for(int i=0; i < viewWindow->tabWidget->count(); i++)
            if(viewWindow->tabWidget->currentIndex() != i)
                viewWindow->tabWidget->setTabEnabled(i, false);
}

void View::updateMessages() {
    if(model->getErrorLog() != nullptr && model->getErrorLog()->isActivated()){
        dialogNoButton = new DialogNoButton(model->getErrorLog()->getTitle(), model->getErrorLog()->getText());
        model->getErrorLog()->setActivated(false);
        dialogNoButton->show();
    }
}

void View::updateHistorical() {
    clearLayout(viewWindow->verticalLayout_localHistory);

    auto historical = dynamic_cast<Historical*>(model->accessDataStorage("Historical"));

    for (auto &transaction : historical->getHistory()){

            auto transactionForm = new TransactionForm;
            if(transaction.isDebit()){
                transactionForm->transactionForm_ui->label_debit->setText("Addebito");
                transactionForm->transactionForm_ui->label_debit->setStyleSheet("QLabel { color : red; }");
            }else{
                transactionForm->transactionForm_ui->label_debit->setText("Accredito");
                transactionForm->transactionForm_ui->label_debit->setStyleSheet("QLabel { color : green; }");
            }
            transactionForm->transactionForm_ui->label_payerName->setText(transaction.getPayerName());
            transactionForm->transactionForm_ui->label_payerIBAN->setText(transaction.getPayerIBAN());
            transactionForm->transactionForm_ui->label_beneficiaryName->setText(transaction.getReceiverName());
            transactionForm->transactionForm_ui->label_beneficiaryIBAN->setText(transaction.getReceiverIBAN());
            transactionForm->transactionForm_ui->label_amount->setText(QString::number(transaction.getAmount()));
            transactionForm->transactionForm_ui->label_causal->setText(transaction.getCausal());
            transactionForm->transactionForm_ui->label_date->setText(transaction.getDate().toString("dddd, dd / MMMM / yyyy"));

            transactionForm->show();
            viewWindow->verticalLayout_localHistory->addWidget(transactionForm);
        }

    viewWindow->label_totalHistorical->setText(QString::number(historical->getTotal()));
    if (historical->getTotal() < 0)
            viewWindow->label_totalHistorical->setStyleSheet("QLabel { color : red; }");
    else
            viewWindow->label_totalHistorical->setStyleSheet("QLabel { color : green; }");
}

void View::updateTransaction(const Account *account, const Conto *conto) const {
    viewWindow->label_currentDate->setText(QDate::currentDate().toString("dddd, dd / MMMM / yyyy"));

    if(viewWindow->radioButton_sendMoney->isChecked()){
            viewWindow->lineEdit_payerName->setText(account->getName() + " " + account->getSurname());
            viewWindow->lineEdit_beneficiaryName->setText("");
            viewWindow->lineEdit_payerIBAN->setText(conto->getIBAN());
            viewWindow->lineEdit_beneficiaryIBAN->setText("");
            viewWindow->lineEdit_payerName->setEnabled(false);
            viewWindow->lineEdit_beneficiaryName->setEnabled(true);
            viewWindow->lineEdit_payerIBAN->setEnabled(false);
            viewWindow->lineEdit_beneficiaryIBAN->setEnabled(true);
            viewWindow->lineEdit_payerIBAN->setStyleSheet("QLineEdit { color : lightGray; }");
        }else{
            viewWindow->lineEdit_beneficiaryName->setText(account->getName() + " " + account->getSurname());
            viewWindow->lineEdit_payerName->setText("");
            viewWindow->lineEdit_beneficiaryIBAN->setText(conto->getIBAN());
            viewWindow->lineEdit_payerIBAN->setText("");
            viewWindow->lineEdit_payerName->setEnabled(true);
            viewWindow->lineEdit_beneficiaryName->setEnabled(false);
            viewWindow->lineEdit_payerIBAN->setEnabled(true);
            viewWindow->lineEdit_beneficiaryIBAN->setEnabled(false);
            viewWindow->lineEdit_beneficiaryIBAN->setStyleSheet("QLineEdit { color : lightGray; }");
        }
}

Conto* View::updateConto() const {
    auto conto = dynamic_cast<Conto*>(model->accessDataStorage("Conto"));


    viewWindow->label_title->setText(conto->getTitle());
    viewWindow->lineEdit_title->setText(viewWindow->label_title->text());

    viewWindow->label_IBAN->setText("IBAN: " + conto->getIBAN());
    viewWindow->label_Saldo->setText(QString::number(conto->getSaldo()));

    viewWindow->label_liquid->setText(" Liquidità: " + QString::number(conto->getLiquid()));
    viewWindow->label_invested->setText(" Investito: " + QString::number(conto->getInvested()));
    float pos = 100*conto->getLiquid()/conto->getSaldo();
    viewWindow->horizontalSlider_percetage->setSliderPosition(static_cast<int>(pos));
    return conto;
}

Account* View::updateAccount() const {
    viewWindow->lineEdit_nameAccount->setEnabled(false);
    viewWindow->lineEdit_surnameAccount->setEnabled(false);
    viewWindow->lineEdit_codiceFiscaleAccount->setEnabled(false);


    for(int i=0; i < viewWindow->tabWidget->count(); i++)
                viewWindow->tabWidget->setTabEnabled(i, true);

    auto account = dynamic_cast<Account*>(model->accessDataStorage("Account"));

    viewWindow->lineEdit_nameAccount->setText(account->getName());
    viewWindow->lineEdit_surnameAccount->setText(account->getSurname());
    viewWindow->lineEdit_codiceFiscaleAccount->setText(account->getCodiceFiscale());
    viewWindow->lineEdit_codiceFiscaleAccount->setStyleSheet("QLineEdit { color : lightGray; }");
    viewWindow->lineEdit_cityAccount->setText(account->getCity());
    viewWindow->lineEdit_CAPAccount->setText(account->getCAP());
    viewWindow->lineEdit_addressAccount->setText(account->getAddress());
    viewWindow->lineEdit_phoneNumberAccount->setText(account->getPhoneNumber());
    viewWindow->lineEdit_mailAccount->setText(account->getMail());
    return account;
}

void View::closeApp() {
   QApplication::exit(0);
}

void View::showTitleEdit() {

   viewWindow->horizontalWidget_title->setVisible(!viewWindow->horizontalWidget_title->isVisible());

}

void View::showSearchOptions() {

    if(viewWindow->horizontalWidget_searchOptions->isVisible()){
        viewWindow->horizontalWidget_searchOptions->setVisible(false);
        viewWindow->pushButton_showOptions->setText("Più opzioni..");
    }else{
        viewWindow->horizontalWidget_searchOptions->setVisible(true);
        viewWindow->pushButton_showOptions->setText("Meno opzioni");
    }

}


void View::radioButtonTransactionClicked() {
    update();
}


void View::searchHistorical(){

    controller->changeHistoricalOrder(viewWindow->radioButton_cronologicalOrder->isChecked(), viewWindow->lineEdit_searchHistorical->text(), viewWindow->dateEdit_from->date(), viewWindow->dateEdit_to->date(), viewWindow->comboBox_options->currentText());

}

void View::searchDateChanged() {

    viewWindow->dateEdit_to->setMinimumDate(viewWindow->dateEdit_from->date());
    viewWindow->dateEdit_from->setMaximumDate(viewWindow->dateEdit_to->date());

    searchHistorical();

}


void View::RESET() {

    controller->reset();

}

void View::doTransaction() {

    std::map<TransactionData , QString> data;
    data[payerName]=viewWindow->lineEdit_payerName->text();
    data[payerIBAN]=viewWindow->lineEdit_payerIBAN->text();
    data[receiverName]=viewWindow->lineEdit_beneficiaryName->text();
    data[receiverIBAN]=viewWindow->lineEdit_beneficiaryIBAN->text();
    data[amount]=viewWindow->lineEdit_amount->text();
    data[causal]=viewWindow->lineEdit_causal->text();
    controller->doTransaction(viewWindow->radioButton_sendMoney->isChecked(), data, QDate::currentDate());

}

void View::cancel() {

    update();

}


//--------------------------------SALVATAGGI-------

void View::accountSave() {

    std::map<AccountData , QString> strings;

    strings.insert(std::make_pair(AccountData::name,viewWindow->lineEdit_nameAccount->text()));
    strings.insert(std::make_pair(AccountData::surname,viewWindow->lineEdit_surnameAccount->text()));
    strings.insert(std::make_pair(AccountData::codiceFiscale,viewWindow->lineEdit_codiceFiscaleAccount->text()));
    strings.insert(std::make_pair(AccountData::city,viewWindow->lineEdit_cityAccount->text()));
    strings.insert(std::make_pair(AccountData::CAP,viewWindow->lineEdit_CAPAccount->text()));
    strings.insert(std::make_pair(AccountData::address,viewWindow->lineEdit_addressAccount->text()));
    strings.insert(std::make_pair(AccountData::phoneNumber,viewWindow->lineEdit_phoneNumberAccount->text()));
    strings.insert(std::make_pair(AccountData::mail,viewWindow->lineEdit_mailAccount->text()));

    controller->accountSave(strings);

}

void View::contoTitleSave() {

    controller->contoSave(viewWindow->lineEdit_title->text());

    showTitleEdit();

}




//---------------------------Controlli del testo--------------------------

void View::lineIBANEdited(const QString &text){

    QString stringa=text;
    QString allowedCharacters="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM ";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    stringa=stringa.toUpper();

    if(stringa.length() != 27)
        lineEdit->setStyleSheet("QLineEdit { color : red; }");
    else{
        if(lineEdit->isEnabled())
            lineEdit->setStyleSheet("QLineEdit { color : black; }");
        else
            lineEdit->setStyleSheet("QLineEdit { color : lightGray; }");
    }

    stringa.remove(' ');
    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}

void View::codiceFiscaleEdited(const QString &text){

    QString stringa=text;
    QString allowedCharacters="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM ";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    stringa=stringa.toUpper();

    if(stringa.length() != 16)
        lineEdit->setStyleSheet("QLineEdit { color : red; }");
    else
        lineEdit->setStyleSheet("QLineEdit { color : black; }");

    stringa.remove(' ');
    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}

void View::lineCAPEdited(const QString &text){

    QString stringa=text;
    QString allowedCharacters="1234567890";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    stringa=stringa.toUpper();

    if(stringa.length() != 5)
        lineEdit->setStyleSheet("QLineEdit { color : red; }");
    else{
        if(lineEdit->isEnabled())
            lineEdit->setStyleSheet("QLineEdit { color : black; }");
        else
            lineEdit->setStyleSheet("QLineEdit { color : lightGray; }");
    }

    stringa.remove(' ');
    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}

void View::lineAmountEdited(const QString &text){

    QString stringa=text;
    QString allowedCharacters="1234567890";


    if(stringa.count('.')<2)
        allowedCharacters = "1234567890.";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    stringa.remove(' ');
    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}


void View::linePhoneNumber(const QString &text){

    QString stringa=text;
    QString allowedCharacters="1234567890";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    stringa=stringa.toUpper();

    if(stringa.length() != 10)
        lineEdit->setStyleSheet("QLineEdit { color : red; }");
    else{
        if(lineEdit->isEnabled())
            lineEdit->setStyleSheet("QLineEdit { color : black; }");
        else
            lineEdit->setStyleSheet("QLineEdit { color : lightGray; }");
    }

    stringa.remove(' ');
    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}

void View::onlyLetters( const QString &text){

    QString stringa=text;
    QString allowedCharacters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";

    auto *lineEdit = dynamic_cast<QLineEdit*>(sender());

    lineEdit->setText(onlySelectedCharacters(stringa, allowedCharacters));

}

//------------------------ Private Method--------


void View::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

QString View::onlySelectedCharacters(QString &stringa, const QString &allowedCharacters) {

    for(int i = 0; i < stringa.length(); i++) {

        if (!allowedCharacters.contains(stringa.at(i)))
            stringa.remove(stringa.at(i));

    }

    return stringa;

}
