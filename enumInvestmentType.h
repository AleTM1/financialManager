//
// Created by alessandro on 26/08/18.
//

#ifndef FINANCIALMANAGER_ENUMINVESTMENTTYPE_H
#define FINANCIALMANAGER_ENUMINVESTMENTTYPE_H

enum InvestmentType {fund, stock, bond};

enum InvestmentData {investmentType, totalInvested, ISIN, entityName, investorName, investorIBAN };

enum StockFundData {sharesNum, actualInvestment};

enum BondData {monthsNumber, deadline};


#endif //FINANCIALMANAGER_ENUMINVESTMENTTYPE_H
