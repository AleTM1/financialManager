//
// Created by alessandro on 07/08/18.
//

#include "Controller.h"
#include "Bond.h"
#include "Stock.h"

void Controller::openingApp() {
  if (model->isFirstOpening()) {
    model->setTabAccountLocked(true);
  } else {
    model->setTabAccountLocked(false);
    model->loadAll();
  }
}

void Controller::reset() {
  model->clearAll();
}

void Controller::changeHistoricalOrder(bool cronologicalOrder, QString txt, QDate from, QDate to, QString optionOrder) {
  ResearchOptions researchOptions;
  if (cronologicalOrder) {
    researchOptions.setOrderTime(OrderTime::cronologicalOrder);
  } else {
    researchOptions.setOrderTime(OrderTime::cronologicalOrderReversed);
  }
  researchOptions.setSearchText(txt);
  researchOptions.setDateFrom(from);
  researchOptions.setDateTo(to);
  if (optionOrder=="Tutto") {
    researchOptions.setOrderOptions(OrderOptions::all);
  } else if (optionOrder=="Addebiti") {
    researchOptions.setOrderOptions(OrderOptions::debits);
  } else {
    researchOptions.setOrderOptions(OrderOptions::credits);
  }
  model->changeHistoricalOrder(researchOptions);
}

void Controller::doTransaction(bool debit, std::map<TransactionData, QString> dataTransaction, QDate date) {
  Transaction transaction(debit,
                          dataTransaction[payerName],
                          dataTransaction[payerIBAN],
                          dataTransaction[receiverName],
                          dataTransaction[receiverIBAN],
                          (dataTransaction[amount]).toFloat(),
                          dataTransaction[causal],
                          date);
  switch (model->doTransaction(transaction)) {
    case 0: model->makeMessageDialogNoButtons("transazione riuscita", "Transazione effettuata con successo!");
      break;
    case 1: model->makeMessageDialogNoButtons("transazione fallita", "Nome dell'ordinante non valido.");
      break;
    case 2: model->makeMessageDialogNoButtons("transazione fallita", "IBAN dell'ordinante non valido.");
      break;
    case 3: model->makeMessageDialogNoButtons("transazione fallita", "Nome del beneficiario non valido.");
      break;
    case 4: model->makeMessageDialogNoButtons("transazione fallita", "IBAN del beneficiario non valido.");
      break;
    case 5: model->makeMessageDialogNoButtons("transazione fallita", "Importo non valido.");
      break;
    case 6:
      model->makeMessageDialogNoButtons("transazione fallita",
                                        "La cifra che si sta tentando di inviare eccede la liquidità massima disponibile.");
      break;
    case 7:
      model->makeMessageDialogNoButtons("transazione fallita",
                                        "La causale deve essere composta da almento 3 caratteri.");
      break;
    default: model->makeMessageDialogNoButtons("transazione fallita", "Errore sconosciuto");
  }
}


//--------------------------------- Salvataggi


void Controller::accountSave(std::map<AccountData, QString> strings) {
  switch (model->saveAccount(strings)) {
    case 0: {
      if (model->isTabAccountLocked()) {
        model->setTabAccountLocked(false);
        model->createAccount();
      }
      model->makeMessageDialogNoButtons("salvataggio riuscito", "Aggiornamento dei dati effettuato con successo!");
      break;
    }
    case 1: model->makeMessageDialogNoButtons("salvataggio fallito", "Nome troppo breve.");
      break;
    case 2: model->makeMessageDialogNoButtons("salvataggio fallito", "Cognome troppo breve");
      break;
    case 3: model->makeMessageDialogNoButtons("salvataggio fallito", "Il Codice Fiscale deve avere 16 caratteri.");
      break;
    case 4: model->makeMessageDialogNoButtons("salvataggio fallito", "Città non valida.");
      break;
    case 5: model->makeMessageDialogNoButtons("salvataggio fallito", "Il CAP deve avere 5 cifre.");
      break;
    case 6: model->makeMessageDialogNoButtons("salvataggio fallito", "Indirizzo troppo breve.");
      break;
    case 7: model->makeMessageDialogNoButtons("salvataggio fallito", "Il numero di telefono deve avere 10 cifre.");
      break;
    case 8: model->makeMessageDialogNoButtons("salvataggio fallito", "Indirizzo mail non valido.");
      break;
    default: model->makeMessageDialogNoButtons("salvataggio fallito", "Errore sconosciuto");
  }
}

void Controller::contoSave(QString string) {
  model->saveConto(string);
}

//---------------------------

void Controller::doInvestment(InvestmentType investmentType, QString ISINcode, float quantity) {
  try {
    if (investmentType==InvestmentType::stock) {
      auto stock = new Stock();
      stock->setSharesNumber(quantity);
      stock->setBuyDate(QDate::currentDate());
      for (auto s:model->getEntitiesList().companies) {
        if (s->getISIN()==ISINcode) {
          stock->setCompany(s);
        }
      }
      switch (model->doInvestment(stock)) {
        case 0 : model->makeMessageDialogNoButtons("investimento riuscito", "Investimento effettuato con succeso");
          break;
        case 1 :model->makeMessageDialogNoButtons("investimento fallito", "Ammontare dell'investimento non valido");
          break;
        default: model->makeMessageDialogNoButtons("investimento fallito", "Errore sconosciuto");
      }
    } else {
      throw std::invalid_argument("InvestmentType expected is stock");
    }
  }
  catch (std::invalid_argument &e) {
    model->makeMessageDialogNoButtons("investimento fallito", e.what());
  }
}

void Controller::doInvestment(InvestmentType investType, QString ISINcode, float investmentAmount, int monthsNumber) {
  try {
    if (investType==InvestmentType::bond) {
      auto bond = new Bond;
      bond->setTotalInvested(investmentAmount);
      bond->setBuyDate(QDate::currentDate());
      bond->setMonthsDuration(monthsNumber, true);
      for (auto s:model->getEntitiesList().companies) {
        if (s->getISIN()==ISINcode) {
          bond->setCompany(s);
        }
      }
      switch (model->doInvestment(bond)) {
        case 0 : model->makeMessageDialogNoButtons("investimento riuscito", "Investimento effettuato con succeso");
          break;
        case 1 :model->makeMessageDialogNoButtons("investimento fallito", "Ammontare dell'investimento non valido");
          break;
        default: model->makeMessageDialogNoButtons("investimento fallito", "Errore sconosciuto");
      }
    } else {
      throw std::invalid_argument("InvestmentType expected is bond");
    }
  }
  catch (std::invalid_argument &e) {
    model->makeMessageDialogNoButtons("investimento fallito", e.what());
  }
}

void Controller::sell(int index) {
  model->removeInvestment(index);
}



