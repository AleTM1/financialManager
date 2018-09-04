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


}


void View::update()  {

    updateMessages();

    if(model->isTabAccountLocked()){

        lockAccountTab();

    }else {

        updateEntitesList();

        auto account = updateAccount();

        auto conto = updateConto();

        updateTransaction(account, conto);

        updateHistorical();

        updateInvestmentManager();

    }

}

void View::lockAccountTab() const {

    viewWindow->lineEdit_nameAccount->setEnabled(true);
    viewWindow->lineEdit_surnameAccount->setEnabled(true);
    viewWindow->lineEdit_codiceFiscaleAccount->setEnabled(true);

    viewWindow->tabWidget->setCurrentIndex(5);

    for(int i=0; i < viewWindow->tabWidget->count(); i++)
            if(viewWindow->tabWidget->currentIndex() != i)
                viewWindow->tabWidget->setTabEnabled(i, false);
}

void View::updateEntitesList() {


    viewWindow->comboBox_entity->clear();

    for (auto e:model->getEntitiesList().companies)
            viewWindow->comboBox_entity->addItem(e->getName());

    updateInvestmentData();

}

void View::updateInvestmentData() {

    auto companies = model->getEntitiesList().companies;

    auto companyName = viewWindow->comboBox_entity->currentText();

    viewWindow->formWidget_bond->hide();
    viewWindow->formWidget_stock->hide();

    auto currentTypeString = viewWindow->comboBox_investmentType->currentText();

    if(currentTypeString == "Azione")
        viewWindow->formWidget_stock->show();
    else if(currentTypeString == "Obbligazione")
        viewWindow->formWidget_bond->show();


    for (auto c:companies)
        if (companyName == c->getName()) {
            viewWindow->label_enetityISIN->setText(c->getISIN());
            viewWindow->label_stockCost->setText(QString::number(c->getShareCost())+"€");
            viewWindow->label_coupon->setText(QString::number(c->getMontlyCoupon()) + "%");

    }

    updateInvestmentAmount();

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

void View::updateInvestmentManager() {
    clearLayout(viewWindow->verticalLayout_investmentManager);

    auto investmentManager = dynamic_cast<InvestmentManager *>(model->accessDataStorage("InvestmentManager"));

    int i=0;
    for (auto &investment : investmentManager->getInvestmentList()) {

        Company* company;
        for (auto c:model->getEntitiesList().companies)
            if(c->getISIN() == investment->getCompany()->getISIN())
                company = c;

        auto investmentForm = new InvestmentForm(controller,i++);

        investmentForm->ui_investmentForm->label_entityName->setText(company->getName());
        investmentForm->ui_investmentForm->label_entityISIN->setText(company->getISIN());
        investmentForm->ui_investmentForm->label_buyDate->setText(investment->getBuyDate().toString("dddd, dd / MMMM / yyyy"));
        investmentForm->ui_investmentForm->label_totalInvestment->setText(QString::number(investment->getTotalInvested())+"€");

        if(auto stock = dynamic_cast<Stock*>(investment)){
            investmentForm->ui_investmentForm->formWidget_stockData->show();
            investmentForm->ui_investmentForm->label_investmentType->setText("Azione");
            investmentForm->ui_investmentForm->label_stockShareNumber->setText(QString::number(stock->getSharesNumber()));
            investmentForm->ui_investmentForm->label_stockActualInvestment->setText(QString::number(stock->getSharesNumber() * company->getShareCost())+"€");
            investmentForm->ui_investmentForm->label_stockShareCost->setText(QString::number(company->getShareCost())+"€");
            investmentForm->ui_investmentForm->label_stockChangeAmount->setText(QString::number(stock->getSharesNumber() * company->getShareCost() - investment->getTotalInvested())+"€");
            investmentForm->ui_investmentForm->pushButton_sell->show();
            if (investment->getTotalInvested() < stock->getSharesNumber() * company->getShareCost()) {
                investmentForm->ui_investmentForm->label_stockActualInvestment->setStyleSheet("QLabel { color : green; }");
                investmentForm->ui_investmentForm->label_stockChangeAmount->setStyleSheet("QLabel { color : green; }");
            }else {
                investmentForm->ui_investmentForm->label_stockActualInvestment->setStyleSheet("QLabel { color : red; }");
                investmentForm->ui_investmentForm->label_stockChangeAmount->setStyleSheet("QLabel { color : red; }");
            }
        }else if(auto bond = dynamic_cast<Bond*>(investment)){
            investmentForm->ui_investmentForm->formWidget_bondData->show();
            investmentForm->ui_investmentForm->label_investmentType->setText("Obbligazione");
            investmentForm->ui_investmentForm->label_bondMonthsNumber->setText(QString::number(bond->getMonthsDuration()));
            investmentForm->ui_investmentForm->label_deadlineDate->setText(bond->getDeadlineDate().toString("dddd, dd / MMMM / yyyy"));
            investmentForm->ui_investmentForm->label_bondCoupon->setText(QString::number(company->getMontlyCoupon()));
            investmentForm->ui_investmentForm->label_bondExpectedYield->setText(QString::number((company->getMontlyCoupon())/100*investment->getTotalInvested()*bond->getMonthsDuration())+"€");
        }




        investmentForm->show();
        viewWindow->verticalLayout_investmentManager->addWidget(investmentForm);

    }

}


void View::refreshInvestmentValue() {

    model->updateInvestmentValue();
    updateInvestmentData();
    updateInvestmentManager();

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
    viewWindow->label_Saldo->setText(QString::number(conto->getSaldo())+"€");

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

void View::doInvestment() {


    if (viewWindow->comboBox_investmentType->currentText() == "Azione")
        controller->doInvestment(InvestmentType::stock, viewWindow->label_enetityISIN->text(), viewWindow->lineEdit_stockshareNumber->text().toFloat() );
    else if(viewWindow->comboBox_investmentType->currentText() == "Obbligazione")
        controller->doInvestment(InvestmentType::bond, viewWindow->label_enetityISIN->text(), viewWindow->lineEdit_investmentAmount->text().toFloat(), viewWindow->comboBox_monthsNumber->currentText().toInt() );

    viewWindow->lineEdit_investmentAmount->setText("");
    viewWindow->lineEdit_stockshareNumber->setText("");

}


void View::cancel() {

    update();

}

void View::updateInvestmentAmount() {

    viewWindow->label_totalInvestment->setText("0€");

    if (viewWindow->comboBox_investmentType->currentText() == "Azione") {
        viewWindow->label_totalInvestment->setText(QString::number(viewWindow->lineEdit_stockshareNumber->text().toFloat() * (viewWindow->label_stockCost->text().remove("€").toFloat())));
    } else if (viewWindow->comboBox_investmentType->currentText() == "Obbligazione") {
        viewWindow->label_totalInvestment->setText(viewWindow->lineEdit_investmentAmount->text());
        viewWindow->label_expectedYield->setText(QString::number(
                viewWindow->lineEdit_investmentAmount->text().toFloat() *
                (viewWindow->comboBox_monthsNumber->currentText().toInt()) *
                (((viewWindow->label_coupon->text()).remove('%').toFloat()) / 100)));

    }


    if (viewWindow->label_totalInvestment->text().toFloat() > dynamic_cast<Conto *>(model->accessDataStorage("Conto"))->getLiquid()) {
            viewWindow->label_totalInvestment->setStyleSheet("QLabel { color : red; }");
            viewWindow->label_totalInvestment->setText(viewWindow->label_totalInvestment->text() + "€ (liquidità insufficiente)");
    } else {
            viewWindow->label_totalInvestment->setStyleSheet("QLabel { color : black; }");
            viewWindow->label_totalInvestment->setText(viewWindow->label_totalInvestment->text() + "€");
    }

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

void View::lineInvestmentEdited(const QString &string) {

    lineAmountEdited(string);

    updateInvestmentAmount();
}

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

