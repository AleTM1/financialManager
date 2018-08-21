//
// Created by alessandro on 16/08/18.
//

#include "Historical.h"


Historical::Historical() {

    groupName = "Historical";

    researchOptions.setOrderTime(OrderTime::cronologicalOrderReversed);
    researchOptions.setOrderOptions(OrderOptions::all);
    researchOptions.setSearchText("");
    researchOptions.setDateFrom(QDate(18,01,01));
    researchOptions.setDateTo(QDate::currentDate());


}



void Historical::addTransaction(Transaction transaction) {

    rawHistory.push_back(transaction);

    saveData();

    updateOrder();
}

void Historical::saveData() {

    data.beginGroup(groupName + "/localHistory");

        data.beginWriteArray("transaction", rawHistory.size());

        int i = 0;
        for (auto &transaction : rawHistory) {
            data.setArrayIndex(i);
            data.setValue("debit", transaction.isDebit());
            data.setValue("payerName", transaction.getPayerName());
            data.setValue("payerIBAN", transaction.getPayerIBAN());
            data.setValue("receiverName", transaction.getReceiverName());
            data.setValue("receiverIBAN", transaction.getReceiverIBAN());
            data.setValue("amount", transaction.getAmount());
            data.setValue("causal", transaction.getCausal());
            data.setValue("date", transaction.getDate());
            i++;
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


const std::list<Transaction> &Historical::getHistory() const {
    return orderedHistory;
}

//-----------ordinamento history------------------


void Historical::setOrder(ResearchOptions &resOpt) {

    researchOptions = resOpt;

    updateOrder();

}

void Historical::updateOrder() {

    orderedHistory = rawHistory;

    if (researchOptions.getOrderTime() == OrderTime::cronologicalOrderReversed)
       orderedHistory.reverse();



    if (researchOptions.getOrderOptions() == OrderOptions :: debits){

        for (auto &transaction : orderedHistory)
            if(!transaction.isDebit())
                orderedHistory.remove(transaction);

    }else if (researchOptions.getOrderOptions() == OrderOptions :: credits){

        for (auto &transaction : orderedHistory)
            if(transaction.isDebit())
                orderedHistory.remove(transaction);

    }

    /*

    for (auto &transaction : orderedHistory)
        if(transaction.getDate() < researchOptions.getDateFrom() || transaction.getDate() > researchOptions.getDateTo())
            orderedHistory.remove(transaction);


    for (auto &transaction : orderedHistory)
        if(!(transaction.getPayerIBAN().contains(researchOptions.getSearchText()) || transaction.getReceiverIBAN().contains(researchOptions.getSearchText()) || transaction.getPayerName().contains(researchOptions.getSearchText()) || transaction.getReceiverName().contains(researchOptions.getSearchText()) || transaction.getCausal().contains(researchOptions.getSearchText())))
            orderedHistory.remove(transaction);

*/

}
