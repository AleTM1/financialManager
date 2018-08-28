//
// Created by alessandro on 25/08/18.
//

#include "Bond.h"

Bond::Bond(){

    investmentType = bond;

}


int Bond::getMonthsDuration() const {
    return monthsDuration;
}

void Bond::setMonthsDuration(int monthsDuration, bool updateDeadline) {

    Bond::monthsDuration = monthsDuration;

    QDate deadlineDate(QDate::currentDate());

    int months = monthsDuration % 12;
    int years = (monthsDuration-months)/12;

    if(deadlineDate.month() + months > 12){
        years += 1;
        months -= 12;
    }

    deadlineDate = deadlineDate.addMonths(months);
    deadlineDate = deadlineDate.addYears(years);

    if(updateDeadline)
    setDeadlineDate(deadlineDate);
}

const QDate &Bond::getDeadlineDate() const {
    return deadlineDate;
}

void Bond::setDeadlineDate(const QDate &deadlineDate) {
    Bond::deadlineDate = deadlineDate;
}

void Bond::showEntityDetails() {

}


