//
// Created by alessandro on 24/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENT_H
#define FINANCIALMANAGER_INVESTMENT_H


#include <QtCore/QString>
#include <QtCore/QDate>
#include "Company.h"
#include "enumInvestmentType.h"

class Investment {

public:

    virtual ~Investment(){}

    virtual void showEntityDetails() = 0;

    float getTotalInvested() const {
        return totalInvested;
    }

    void setTotalInvested(float totalInvested) {
        Investment::totalInvested = totalInvested;
    }

    InvestmentType getInvestmentType() const {
        return investmentType;
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

    Company *getEntity() const {
        return company;
    }

    virtual void setEntity(Company *entity) {
        Investment::company = entity;
    }

    const QDate &getBuyDate() const {
        return buyDate;
    }

    void setBuyDate(const QDate &buyDate) {
        Investment::buyDate = buyDate;
    }

protected:

    float totalInvested;
    InvestmentType investmentType;
    QString investorIBAN;
    QString investorName;
    Company* company;
    QDate buyDate;
};


#endif //FINANCIALMANAGER_INVESTMENT_H
