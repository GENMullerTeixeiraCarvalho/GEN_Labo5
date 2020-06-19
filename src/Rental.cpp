#include "Rental.h"

#include <utility>

std::ostream& operator<<(std::ostream& os, const Rental& rental) {
    os << rental._movie->getTitle() << "\t" << rental.getAmount();
    return os;
}

Rental::Rental( std::shared_ptr<Movie> movie, int daysRented )
        : _movie(std::move( movie ))
        , _daysRented( daysRented ) {}
