//
// Created by alessandro on 25/08/18.
//

#include "Company.h"

float Company::getMontlyCoupon() const {
    return montlyCoupon;
}

void Company::setMontlyCoupon(float coupon) {
    Company::montlyCoupon = coupon;
}
