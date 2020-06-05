// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

#include <iostream>

class Rental {
    friend std::ostream& operator<<(std::ostream& os, const Rental& rental);
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;
    double getAmount() const;
    int getFrequentRenterPoints() const;

private:
    Movie _movie;
    int _daysRented;
};

std::ostream& operator<<(std::ostream& os, const Rental& rental);

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

inline double Rental::
getAmount() const { return _movie.getPriceCode()->getAmount(_daysRented); }

inline int Rental::
getFrequentRenterPoints() const {
    return _movie.getPriceCode()->getFrequentRenterPoints(_daysRented);
}

#endif // RENTAL_H