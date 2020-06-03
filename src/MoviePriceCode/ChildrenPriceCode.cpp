#include "ChildrenPriceCode.h"

double ChildrenPriceCode::getAmount(int nbRentedDays) {
    double amount = 1.5;
    if (nbRentedDays > 3)
        amount += (nbRentedDays - 3) * 1.5;

    return amount;
}

int ChildrenPriceCode::getFrequentRenterPoints(int nbRentedDays) {
    if (nbRentedDays > 1)
        return 2;

    return 1;
}

std::shared_ptr<ChildrenPriceCode> ChildrenPriceCode::getPriceCode() {
    if (childrenPriceCode == nullptr)
        childrenPriceCode = std::shared_ptr<ChildrenPriceCode>();

    return childrenPriceCode;
}
