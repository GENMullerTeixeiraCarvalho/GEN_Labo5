#include "ChildrenPriceCode.h"

std::shared_ptr<ChildrenPriceCode> ChildrenPriceCode::childrenPriceCode = nullptr;

double ChildrenPriceCode::getAmount(int nbRentedDays) {
    double amount = 1.5;
    if (nbRentedDays > 3)
        amount += (nbRentedDays - 3) * 1.5;

    return amount;
}

int ChildrenPriceCode::getFrequentRenterPoints(int nbRentedDays) {
    return 1;
}

std::shared_ptr<ChildrenPriceCode> ChildrenPriceCode::getPriceCode() {
    if (childrenPriceCode == nullptr)
        childrenPriceCode = std::shared_ptr<ChildrenPriceCode>(new ChildrenPriceCode());

    return childrenPriceCode;
}
