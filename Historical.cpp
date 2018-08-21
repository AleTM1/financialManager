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




    std::vector<std::list<Transaction>::iterator> iterators;


    if (researchOptions.getOrderOptions() == OrderOptions :: debits){


        for (auto iterator=orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
            if(!iterator->isDebit())
                iterators.push_back(iterator);


    }else if (researchOptions.getOrderOptions() == OrderOptions :: credits){

        for (auto iterator=orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
            if(iterator->isDebit())
                iterators.push_back(iterator);

    }

    //TODO generalizza questo comportamento

    for (auto it : iterators)
        orderedHistory.erase(it);

/*

    for (auto iterator=orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
        if(iterator->getDate() < researchOptions.getDateFrom() || iterator->getDate() > researchOptions.getDateTo())
            orderedHistory.erase(iterator++);


    for (auto iterator=orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
        if(!(iterator->getPayerIBAN().contains(researchOptions.getSearchText()) || iterator->getReceiverIBAN().contains(researchOptions.getSearchText()) || iterator->getPayerName().contains(researchOptions.getSearchText()) || iterator->getReceiverName().contains(researchOptions.getSearchText()) || iterator->getCausal().contains(researchOptions.getSearchText())))
            orderedHistory.erase(iterator++);

*/

    if (researchOptions.getOrderTime() == OrderTime::cronologicalOrderReversed)
        orderedHistory.reverse();

}
