#ifndef GEN_LABO5_REGULARPRICECODE_H
#define GEN_LABO5_REGULARPRICECODE_H

#include <memory>
#include "MoviePriceCode.h"

class RegularPriceCode : public MoviePriceCode {
public:
    double getAmount(int nbRentedDays) override;
    int getFrequentRenterPoints(int nbRentedDays) override;

    static std::shared_ptr<RegularPriceCode> getPriceCode();

protected:
    RegularPriceCode() = default;
    static std::shared_ptr<RegularPriceCode> regularPriceCode;
};


#endif //GEN_LABO5_REGULARPRICECODE_H
