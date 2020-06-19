#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Customer.h"
#include "../src/MoviePriceCode/NewReleasePriceCode.h"
#include "../src/MoviePriceCode/ChildrenPriceCode.h"
#include "../src/MoviePriceCode/RegularPriceCode.h"

using ::testing::Return;

class RentalMock : public Rental{
public:
    RentalMock( int daysRented ) : Rental(nullptr, daysRented) {}
    MOCK_METHOD(double, getAmount, (), (const));
    MOCK_METHOD(int, getFrequentRenterPoints, (), (const));
    MOCK_METHOD(std::string, getTitleMovie, (), (const));
};

TEST(Customer, StatementShouldWork) {
    Customer customer("Olivier");
    std::shared_ptr<RentalMock> ptrRental1 = std::make_shared<RentalMock>(7);
    std::shared_ptr<RentalMock> ptrRental2 = std::make_shared<RentalMock>(5);
    std::shared_ptr<RentalMock> ptrRental3 = std::make_shared<RentalMock>(3);

    EXPECT_CALL(*ptrRental1, getAmount()).WillRepeatedly(Return(9.5));
    EXPECT_CALL(*ptrRental1, getFrequentRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*ptrRental1, getTitleMovie()).WillRepeatedly(Return("Karate Kid"));
    customer.addRental(ptrRental1);
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