#include "Rental.h"

#include <utility>

Rental::Rental( std::shared_ptr<Movie> movie, int daysRented )
        : _movie(std::move( movie ))
        , _daysRented( daysRented ) {}
