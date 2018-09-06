//
// Created by alessandro on 16/08/18.
//

#include "Historical.h"

Historical::Historical()
{

    groupName = "Historical";

    researchOptions.setOrderTime(OrderTime::cronologicalOrderReversed);
    researchOptions.setOrderOptions(OrderOptions::all);
    researchOptions.setSearchText("");
    researchOptions.setDateFrom(QDate(18, 01, 01));
    researchOptions.setDateTo(QDate::currentDate());

}

void Historical::addTransaction(Transaction transaction)
{

    rawHistory.push_back(transaction);

    saveData();

    updateOrder();
}

void Historical::saveData()
{

    data.beginGroup(groupName+"/localHistory");

    data.beginWriteArray("transaction", rawHistory.size());

    int i = 0;
    for (auto& transaction : rawHistory) {
        data.setArrayIndex(i);
        data.setValue(QString::number(TransactionData::debit), transaction.isDebit());
        data.setValue(QString::number(TransactionData::payerName), transaction.getPayerName());
        data.setValue(QString::number(TransactionData::payerIBAN), transaction.getPayerIBAN());
        data.setValue(QString::number(TransactionData::receiverName), transaction.getReceiverName());
        data.setValue(QString::number(TransactionData::receiverIBAN), transaction.getReceiverIBAN());
        data.setValue(QString::number(TransactionData::amount), transaction.getAmount());
        data.setValue(QString::number(TransactionData::causal), transaction.getCausal());
        data.setValue(QString::number(TransactionData::date), transaction.getDate());
        i++;
    }

    data.endArray();

    data.endGroup();

    data.sync();
}

void Historical::loadData()
{

    rawHistory.clear();

    data.beginGroup(groupName+"/localHistory");

    int size = data.beginReadArray("transaction");
    for (int i = 0; i<size; i++) {
        data.setArrayIndex(i);
        Transaction transaction(data.value(QString::number(TransactionData::debit)).toBool(), data.value(QString::number(TransactionData::payerName)).toString(), data.value(QString::number(TransactionData::payerIBAN)).toString(), data.value(QString::number(TransactionData::receiverName)).toString(), data.value(QString::number(TransactionData::receiverIBAN)).toString(), data.value(QString::number(TransactionData::amount)).toFloat(), data.value(QString::number(TransactionData::causal)).toString(), data.value(QString::number(TransactionData::date)).toDate());
        rawHistory.push_back(transaction);
    }

    data.endArray();

    data.endGroup();

    data.sync();

    updateOrder();

}

const std::list<Transaction>& Historical::getHistory() const
{

    return orderedHistory;
}

float Historical::getTotal() const
{

    return total;
}

//-----------ordinamento history------------------


void Historical::setOrder(ResearchOptions& resOpt)
{

    researchOptions = resOpt;

    updateOrder();

}

void Historical::updateOrder()
{

    orderedHistory = rawHistory;

    std::vector<std::list<Transaction>::iterator> iterators;

    float tot = 0;

    if (researchOptions.getOrderOptions()==OrderOptions::all) {
        for (auto iterator = orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
            if (iterator->getDate()<researchOptions.getDateFrom() || iterator->getDate()>researchOptions.getDateTo())
                iterators.push_back(iterator);
            else if (!(iterator->getPayerIBAN().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getReceiverIBAN().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getPayerName().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getReceiverName().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getCausal().contains(researchOptions.getSearchText(), Qt::CaseInsensitive)))
                iterators.push_back(iterator);
            else {
                if (iterator->isDebit())
                    tot -= iterator->getAmount();
                else
                    tot += iterator->getAmount();
            }
    }
    else {

        for (auto iterator = orderedHistory.begin(); iterator!=orderedHistory.end(); iterator++)
            if (iterator->isDebit()==(researchOptions.getOrderOptions()==OrderOptions::credits))
                iterators.push_back(iterator);
            else if (iterator->getDate()<researchOptions.getDateFrom() || iterator->getDate()>researchOptions.getDateTo())
                iterators.push_back(iterator);
            else if (!(iterator->getPayerIBAN().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getReceiverIBAN().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getPayerName().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getReceiverName().contains(researchOptions.getSearchText(), Qt::CaseInsensitive) || iterator->getCausal().contains(researchOptions.getSearchText(), Qt::CaseInsensitive)))
                iterators.push_back(iterator);
            else {
                if (iterator->isDebit())
                    tot -= iterator->getAmount();
                else
                    tot += iterator->getAmount();
            }

    }

    for (auto it : iterators)
        orderedHistory.erase(it);

    total = tot;

    if (researchOptions.getOrderTime()==OrderTime::cronologicalOrderReversed)
        orderedHistory.reverse();

}

