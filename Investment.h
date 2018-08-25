//
// Created by alessandro on 24/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENT_H
#define FINANCIALMANAGER_INVESTMENT_H


#include <QtCore/QString>
#include "Entity.h"

class Investment {

public:

    enum InvestmentType {fund, stock, bond};

    virtual ~Investment(){}

    virtual void showEnteDetails() = 0;

    float getTotalInvested() const {
        return totalInvested;
    }

    void setTotalInvested(float totalInvested) {
        Investment::totalInvested = totalInvested;
    }

    InvestmentType getInvestmentType() const {
        return investmentType;
    }

    void setInvestmentType(InvestmentType investmentType) {
        Investment::investmentType = investmentType;
    }

    const QString &getInvestorIBAN() const {
        return investorIBAN;
    }

    void setInvestorIBAN(const QString &investorIBAN) {
        Investment::investorIBAN = investorIBAN;
    }

    const QString &getInvestorName() const {
        return investorName;
    }

    void setInvestorName(const QString &investorName) {
        Investment::investorName = investorName;
    }

    Entity *getEntity() const {
        return entity;
    }

    void setEntity(Entity *entity) {
        Investment::entity = entity;
    }

protected:

    float totalInvested;
    InvestmentType investmentType;
    QString investorIBAN;
    QString investorName;
    Entity* entity;

};


#endif //FINANCIALMANAGER_INVESTMENT_H
