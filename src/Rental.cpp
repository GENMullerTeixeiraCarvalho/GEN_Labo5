#include "Rental.h"

std::ostream& operator<<(std::ostream& os, const Rental& rental) {
    os << rental._movie.getTitle() << "\t" << rental.getAmount();
    return os;
}

Rental::Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}
