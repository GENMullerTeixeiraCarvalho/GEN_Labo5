#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Customer.h"
#include "../src/Movie/RegularMovie.h"
#include "../src/Movie/ChildrenMovie.h"
#include "../src/Movie/NewReleaseMovie.h"

TEST(Customer, StatementShouldWork) {
    Customer customer("Olivier");
    customer.addRental( Rental( RegularMovie("Karate Kid"), 7));
    customer.addRental( Rental( NewReleaseMovie( "Avengers: Endgame"), 5));
    customer.addRental( Rental( ChildrenMovie("Snow White"), 3 ));

    const std::string EXPECTED_RES = "Rental Record for Olivier\n"
                                "\tKarate Kid\t9.5\n"
                                "\tAvengers: Endgame\t15\n"
                                "\tSnow White\t1.5\n"
                                "Amount owed is 26\n"
                                "You earned 4 frequent renter points";

    EXPECT_EQ(customer.statement(), EXPECTED_RES);
}