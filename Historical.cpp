//
// Created by alessandro on 16/08/18.
//

#include "Historical.h"


void Historical::addTransaction(Transaction transaction) {

    history.push_back(transaction);

    saveData();
}

void Historical::saveData() {

    data.beginGroup(groupName + "/localHistory");

        data.beginWriteArray("transaction", history.size());

        for (int i = 0; i < history.size(); i++) {
            data.setArrayIndex(i);
            data.setValue("debit", history[i].isDebit());
            data.setValue("payerName", history[i].getPayerName());
            data.setValue("payerIBAN", history[i].getPayerIBAN());
            data.setValue("receiverName", history[i].getReceiverName());
            data.setValue("receiverIBAN", history[i].getReceiverIBAN());
            data.setValue("amount", history[i].getAmount());
            data.setValue("causal", history[i].getCausal());
            data.setValue("date", history[i].getDate());
        }

        data.endArray();

    data.endGroup();


    data.sync();
}

void Historical::loadData() {

    history.clear();

    data.beginGroup(groupName + "/localHistory");

        int size = data.beginReadArray("transaction");
            for (int i = 0; i < size; i++) {
                data.setArrayIndex(i);
                Transaction transaction(data.value("debit").toBool(),data.value("payerName").toString(),data.value("payerIBAN").toString(),data.value("receiverName").toString(),data.value("receiverIBAN").toString(),data.value("amount").toInt(),data.value("causal").toString(),data.value("date").toDate());
                history.push_back(transaction);
            }

        data.endArray();

    data.endGroup();


    data.sync();
}


const std::vector<Transaction> &Historical::getHistory() const {
    return history;
}
