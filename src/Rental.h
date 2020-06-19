// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

#include <iostream>

class Rental {
    friend std::ostream& operator<<(std::ostream& os, const Rental& rental);
public:
    Rental( std::shared_ptr<Movie> movie, int daysRented );

    int getDaysRented() const;
    const std::shared_ptr<Movie> getMovie() const;
    double getAmount() const;
    int getFrequentRenterPoints() const;

private:
    std::shared_ptr<Movie> _movie;
    int _daysRented;
};

std::ostream& operator<<(std::ostream& os, const Rental& rental);

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const std::shared_ptr<Movie> Rental::
getMovie() const { return _movie; }

inline double Rental::
getAmount() const { return _movie->getPriceCode()->getAmount(_daysRented); }

inline int Rental::
getFrequentRenterPoints() const {
    return _movie->getPriceCode()->getFrequentRenterPoints(_daysRented);
}

#endif // RENTAL_H