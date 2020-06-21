#include <iostream>

#include "Customer.h"
#include "MoviePriceCode/NewReleasePriceCode.h"
#include "MoviePriceCode/ChildrenPriceCode.h"
#include "MoviePriceCode/RegularPriceCode.h"

int main(int argc, char** argv) {

    Customer customer("Olivier");
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Karate Kid", RegularPriceCode::getPriceCode()), 7));
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Avengers: Endgame", NewReleasePriceCode::getPriceCode()), 5));
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Snow White", ChildrenPriceCode::getPriceCode()), 3 ));

    std::cout << customer.statement() << std::endl;

    return 0;
}