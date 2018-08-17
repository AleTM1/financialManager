//
// Created by alessandro on 16/08/18.
//

#include "Historical.h"


void Historical::addTransaction(Transaction) {



    saveData();
}

void Historical::saveData() {

    data.beginGroup(groupName);

    data.setValue("localHistory", QVariant::fromValue<std::vector<Transaction>>( history ));

    data.endGroup();


    data.sync();
}

void Historical::loadData() {

}
