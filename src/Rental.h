// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

#include <iostream>

class Rental {
public:
    Rental( std::shared_ptr<Movie> movie, int daysRented );

    virtual double getAmount() const;
    virtual int getFrequentRenterPoints() const;
    virtual std::string getTitleMovie() const;

private:
    std::shared_ptr<Movie> _movie;
    int _daysRented;
};

inline double Rental::
getAmount() const { return _movie->getPriceCode()->getAmount(_daysRented); }

inline std::string Rental::
getTitleMovie() const { return _movie->getTitle(); }

inline int Rental::
getFrequentRenterPoints() const {
    return _movie->getPriceCode()->getFrequentRenterPoints(_daysRented);
}

#endif // RENTAL_H