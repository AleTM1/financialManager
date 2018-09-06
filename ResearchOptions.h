//
// Created by alessandro on 20/08/18.
//

#ifndef FINANCIALMANAGER_RESEARCHOPTIONS_H
#define FINANCIALMANAGER_RESEARCHOPTIONS_H

#include <QtCore/QString>
#include <QtCore/QDate>
#include "enumOrder.h"

class ResearchOptions {

public:

    explicit ResearchOptions(OrderTime oT = OrderTime::cronologicalOrderReversed, OrderOptions oO = OrderOptions::all, QString sT = "", QDate dF = QDate(18, 1, 1), QDate dT = QDate::currentDate()) :orderTime(oT), orderOptions(oO), searchText(sT), dateFrom(dF), dateTo(dT) { }

    void setOrderTime(OrderTime orderTime)
    {

        ResearchOptions::orderTime = orderTime;
    }

    void setOrderOptions(OrderOptions orderOptions)
    {

        ResearchOptions::orderOptions = orderOptions;
    }

    void setSearchText(const QString& searchText)
    {

        ResearchOptions::searchText = searchText;
    }

    void setDateFrom(const QDate& dateFrom)
    {

        ResearchOptions::dateFrom = dateFrom;
    }

    void setDateTo(const QDate& dateTo)
    {

        ResearchOptions::dateTo = dateTo;
    }

    OrderTime getOrderTime() const
    {

        return orderTime;
    }

    OrderOptions getOrderOptions() const
    {

        return orderOptions;
    }

    const QString& getSearchText() const
    {

        return searchText;
    }

    const QDate& getDateFrom() const
    {

        return dateFrom;
    }

    const QDate& getDateTo() const
    {

        return dateTo;
    }

private:

    OrderTime orderTime;

    OrderOptions orderOptions;

    QString searchText;

    QDate dateFrom;

    QDate dateTo;

};

#endif //FINANCIALMANAGER_RESEARCHOPTIONS_H
