#include <iostream>

#include "Customer.h"
#include "MoviePriceCode/NewReleasePriceCode.h"
#include "MoviePriceCode/ChildrenPriceCode.h"
#include "MoviePriceCode/RegularPriceCode.h"

int main(int argc, char** argv) {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid", RegularPriceCode::getPriceCode()), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", NewReleasePriceCode::getPriceCode()), 5));
    customer.addRental( Rental( Movie("Snow White", ChildrenPriceCode::getPriceCode()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}