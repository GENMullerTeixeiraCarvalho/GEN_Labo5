#include <iostream>

#include "Customer.h"
#include "Movie/RegularMovie.h"
#include "Movie/NewReleaseMovie.h"
#include "Movie/ChildrenMovie.h"

int main(int argc, char** argv) {

    Customer customer("Olivier");
    customer.addRental( Rental( RegularMovie("Karate Kid"), 7));
    customer.addRental( Rental( NewReleaseMovie( "Avengers: Endgame"), 5));
    customer.addRental( Rental( ChildrenMovie("Snow White"), 3 ));

    std::cout << customer.statement() << std::endl;

    std::cout << "I'm in main" << std::endl;
    return 0;
}