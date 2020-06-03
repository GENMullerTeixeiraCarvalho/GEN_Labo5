#include <iostream>

#include "Customer.h"

int main(int argc, char** argv) {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << customer.statement() << std::endl;

    std::cout << "I'm in main" << std::endl;
    return 0;
}