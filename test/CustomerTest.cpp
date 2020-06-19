#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Customer.h"
#include "../src/MoviePriceCode/NewReleasePriceCode.h"
#include "../src/MoviePriceCode/ChildrenPriceCode.h"
#include "../src/MoviePriceCode/RegularPriceCode.h"

TEST(Customer, StatementShouldWork) {
    Customer customer("Olivier");
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Karate Kid", RegularPriceCode::getPriceCode()), 7));
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Avengers: Endgame", NewReleasePriceCode::getPriceCode()), 5));
    customer.addRental( std::make_shared<Rental>( std::make_shared<Movie>("Snow White", ChildrenPriceCode::getPriceCode()), 3 ));

    const std::string EXPECTED_RES = "Rental Record for Olivier\n"
                                "\tKarate Kid\t9.5\n"
                                "\tAvengers: Endgame\t15\n"
                                "\tSnow White\t1.5\n"
                                "Amount owed is 26\n"
                                "You earned 4 frequent renter points";

    EXPECT_EQ(customer.statement(), EXPECTED_RES);
}