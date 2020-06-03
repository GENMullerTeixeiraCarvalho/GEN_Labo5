#include <iostream>

#include "Customer.h"
#include "MoviePriceCode/NewReleasePriceCode.h"
#include "MoviePriceCode/ChildrenPriceCode.h"

int main(int argc, char** argv) {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", NewReleasePriceCode::getPriceCode()), 5));
    customer.addRental( Rental( Movie("Snow White", ChildrenPriceCode::getPriceCode()), 3 ));

    std::cout << customer.statement() << std::endl;

    std::cout << "I'm in main" << std::endl;
    return 0;
}