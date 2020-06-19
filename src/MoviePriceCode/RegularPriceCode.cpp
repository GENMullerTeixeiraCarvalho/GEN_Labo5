#include "RegularPriceCode.h"

std::shared_ptr<RegularPriceCode> RegularPriceCode::regularPriceCode = nullptr;

double RegularPriceCode::getAmount(int nbRentedDays) {
    double amount = 2;
    if (nbRentedDays > 2)
        amount += (nbRentedDays - 2) * 1.5;

    return amount;
}

int RegularPriceCode::getFrequentRenterPoints(int nbRentedDays) {
    return 1;
}

std::shared_ptr<RegularPriceCode> RegularPriceCode::getPriceCode() {
    if (regularPriceCode == nullptr)
        regularPriceCode = std::shared_ptr<RegularPriceCode>(new RegularPriceCode());

    return regularPriceCode;
}
