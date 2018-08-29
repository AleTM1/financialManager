//
// Created by alessandro on 28/08/18.
//

#include "Timer.h"



Timer::Timer(View* v, QWidget *parent) : view(v), QWidget(parent) {

    auto timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(4000);

}

void Timer::refresh() {

    view->refreshInvestmentValue();

}