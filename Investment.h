//
// Created by alessandro on 24/08/18.
//

#ifndef FINANCIALMANAGER_INVESTMENT_H
#define FINANCIALMANAGER_INVESTMENT_H


#include <QtCore/QString>

class Investment {

public:

    enum InvestmentType {fund, stock, bond};

    virtual ~Investment(){}

    virtual void showDetails() = 0;

    const QString &getISIN() const {
        return ISIN;
    }

    void setISIN(const QString &ISIN) {
        Investment::ISIN = ISIN;
    }

    const QString &getInvestmentName() const {
        return investmentName;
    }

    void setInvestmentName(const QString &investmentName) {
        Investment::investmentName = investmentName;
    }

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

protected:

    QString ISIN;
    QString investmentName;
    float totalInvested;
    InvestmentType investmentType;
    QString investorIBAN;

};


#endif //FINANCIALMANAGER_INVESTMENT_H
