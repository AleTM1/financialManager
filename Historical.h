//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_HISTORICAL_H
#define FINANCIALMANAGER_HISTORICAL_H


#include "AbstractDataStorage.h"
#include "Conto.h"
#include "enumOrder.h"
#include "ResearchOptions.h"

class Historical : public AbstractDataStorage{

public:

    Historical(){groupName="Historical";}

    void addTransaction(Transaction);

    virtual void saveData() override;

    virtual void loadData() override;

    const std::vector<Transaction> &getHistory() const;

    void setOrder(OrderTime);

private:

    void updateOrder();

protected:

    std::vector<Transaction> rawHistory;

    std::vector<Transaction> orderedHistory;

    OrderTime selectedTimeOrder = cronologicalOrderReversed;

};


#endif //FINANCIALMANAGER_HISTORICAL_H
