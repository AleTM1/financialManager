//
// Created by alessandro on 16/08/18.
//

#ifndef FINANCIALMANAGER_HISTORICAL_H
#define FINANCIALMANAGER_HISTORICAL_H


#include "AbstractDataStorage.h"
#include "Conto.h"

class Historical : public AbstractDataStorage{

public:

    Historical():group("Historical"){}

    void saveData(Transaction){}


protected:


};


#endif //FINANCIALMANAGER_HISTORICAL_H
