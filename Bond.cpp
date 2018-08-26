//
// Created by alessandro on 25/08/18.
//

#include "Bond.h"

Bond::Bond(int monthsNumber){

    investmentType = bond;

    monthsDuration = monthsNumber;

}


int Bond::getMonthsDuration() const {
    return monthsDuration;
}

void Bond::setMonthsDuration(int monthsDuration) {
    Bond::monthsDuration = monthsDuration;  //TODO collega DeadLine
}

const QDate &Bond::getDeadlineDate() const {
    return deadlineDate;
}

void Bond::setDeadlineDate(const QDate &deadlineDate) {
    Bond::deadlineDate = deadlineDate;  //TODO collega a Months Duration
}

void Bond::showEntityDetails() {

}


