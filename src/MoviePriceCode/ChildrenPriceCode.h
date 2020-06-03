#ifndef GEN_LABO5_CHILDRENPRICECODE_H
#define GEN_LABO5_CHILDRENPRICECODE_H

#include <memory>

#include "MoviePriceCode.h"

class ChildrenPriceCode : public MoviePriceCode {
public:
    double getAmount(int nbRentedDays) override;
    int getFrequentRenterPoints(int nbRentedDays) override;

    static std::shared_ptr<ChildrenPriceCode> getPriceCode();

protected:
    ChildrenPriceCode() = default;
    static std::shared_ptr<ChildrenPriceCode> childrenPriceCode;
};



#endif //GEN_LABO5_CHILDRENPRICECODE_H
