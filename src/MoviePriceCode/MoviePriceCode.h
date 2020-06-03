#ifndef GEN_LABO5_MOVIEPRICECODE_H
#define GEN_LABO5_MOVIEPRICECODE_H


class MoviePriceCode {
public:
    virtual double getAmount(int nbRentedDays) = 0;
    virtual int getFrequentRenterPoints(int nbRentedDays) = 0;
};


#endif //GEN_LABO5_MOVIEPRICECODE_H
