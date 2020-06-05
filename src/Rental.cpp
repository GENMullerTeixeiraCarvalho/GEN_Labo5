#include "Rental.h"

std::ostream& operator<<(std::ostream& os, const Rental& rental) {
    std::shared_ptr<MoviePriceCode> priceCode = rental._movie.getPriceCode();
    double thisAmount = priceCode->getAmount(rental._daysRented);

    os << rental._movie.getTitle() << "\t" << thisAmount;

    return os;
}