//
// Created by alessandro on 16/08/18.
//

#include "Historical.h"


void Historical::addTransaction(Transaction transaction) {

    rawHistory.push_back(transaction);

    saveData();

    updateOrder();
}

void Historical::saveData() {

    data.beginGroup(groupName + "/localHistory");

        data.beginWriteArray("transaction", rawHistory.size());

        for (int i = 0; i < rawHistory.size(); i++) {
            data.setArrayIndex(i);
            data.setValue("debit", rawHistory[i].isDebit());
            data.setValue("payerName", rawHistory[i].getPayerName());
            data.setValue("payerIBAN", rawHistory[i].getPayerIBAN());
            data.setValue("receiverName", rawHistory[i].getReceiverName());
            data.setValue("receiverIBAN", rawHistory[i].getReceiverIBAN());
            data.setValue("amount", rawHistory[i].getAmount());
            data.setValue("causal", rawHistory[i].getCausal());
            data.setValue("date", rawHistory[i].getDate());
        }

        data.endArray();

    data.endGroup();


    data.sync();
}

void Historical::loadData() {

    rawHistory.clear();

    data.beginGroup(groupName + "/localHistory");

        int size = data.beginReadArray("transaction");
            for (int i = 0; i < size; i++) {
                data.setArrayIndex(i);
                Transaction transaction(data.value("debit").toBool(),data.value("payerName").toString(),data.value("payerIBAN").toString(),data.value("receiverName").toString(),data.value("receiverIBAN").toString(),data.value("amount").toInt(),data.value("causal").toString(),data.value("date").toDate());
                rawHistory.push_back(transaction);
            }

        data.endArray();

    data.endGroup();

    data.sync();

    updateOrder();

}


const std::vector<Transaction> &Historical::getHistory() const {
    return orderedHistory;
}

//-----------ordinamento history------------------


void Historical::setOrder(OrderTime o) {

    selectedTimeOrder = o;

    updateOrder();

}

void Historical::updateOrder() {

    if (selectedTimeOrder == OrderTime::cronologicalOrder)

        orderedHistory = rawHistory;

    else {

        int size = rawHistory.size();

        orderedHistory.clear();

        for (int i = size - 1; i >= 0; i--) {

            orderedHistory.push_back(rawHistory[i]);

        }

    }
}
