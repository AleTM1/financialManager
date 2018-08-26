//
// Created by alessandro on 25/08/18.
//

#ifndef FINANCIALMANAGER_BOND_H
#define FINANCIALMANAGER_BOND_H


#include <QtCore/QDate>
#include "Investment.h"

class Bond :public Investment{

public:

    Bond(float investmentAmount, int monthsNumber);

    virtual void showEntityDetails() override ;

    int getMonthsDuration() const;

    void setMonthsDuration(int monthsDuration);

    const QDate &getDeadlineDate() const;

    void setDeadlineDate(const QDate &deadlineDate);

protected:

    int monthsDuration;
    QDate deadlineDate;

};


#endif //FINANCIALMANAGER_BOND_H
