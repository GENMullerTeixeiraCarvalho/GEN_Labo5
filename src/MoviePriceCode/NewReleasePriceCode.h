#ifndef GEN_LABO5_NEWRELEASEPRICECODE_H
#define GEN_LABO5_NEWRELEASEPRICECODE_H

#include <memory>
#include "MoviePriceCode.h"

class NewReleasePriceCode : public MoviePriceCode {
public:
    double getAmount(int nbRentedDays) override;
    int getFrequentRenterPoints(int nbRentedDays) override;

    static std::shared_ptr<NewReleasePriceCode> getPriceCode();

protected:
    NewReleasePriceCode() = default;
    static std::shared_ptr<NewReleasePriceCode> newReleasePriceCode;
};


#endif //GEN_LABO5_NEWRELEASERICECODE_H
