#include "NewReleasePriceCode.h"

std::shared_ptr<NewReleasePriceCode> NewReleasePriceCode::newReleasePriceCode = nullptr;

double NewReleasePriceCode::getAmount(int nbRentedDays) {
    return nbRentedDays * 3;
}

int NewReleasePriceCode::getFrequentRenterPoints(int nbRentedDays) {
    if (nbRentedDays > 1)
        return 2;

    return 1;
}

std::shared_ptr<NewReleasePriceCode> NewReleasePriceCode::getPriceCode() {
    if (newReleasePriceCode == nullptr)
        newReleasePriceCode = std::shared_ptr<NewReleasePriceCode>(new NewReleasePriceCode());

    return newReleasePriceCode;
}
