#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Customer.h"
#include "../src/Rental.h"

using ::testing::Return;

class RentalMock : public Rental{
public:
    explicit RentalMock( int daysRented ) : Rental(nullptr, daysRented) {}
    MOCK_METHOD(double, getAmount, (), (const));
    MOCK_METHOD(int, getFrequentRenterPoints, (), (const));
    MOCK_METHOD(std::string, getTitleMovie, (), (const));
};

TEST(Customer, getNameShouldWork) {
    Customer customer("Olivier");

    EXPECT_EQ(customer.getName(), "Olivier");
}

TEST(Customer, getTotalAmountShouldWork) {
    Customer customer("Olivier");
    EXPECT_EQ(customer.getTotalAmount(), 0);

    std::shared_ptr<RentalMock> ptrRental1 = std::make_shared<RentalMock>(7);
    std::shared_ptr<RentalMock> ptrRental2 = std::make_shared<RentalMock>(2);

    EXPECT_CALL(*ptrRental1, getAmount()).WillRepeatedly(Return(11.5));
    EXPECT_CALL(*ptrRental2, getAmount()).WillRepeatedly(Return(12));

    customer.addRental(ptrRental1);
    EXPECT_EQ(customer.getTotalAmount(), 11.5);

    customer.addRental(ptrRental2);
    EXPECT_EQ(customer.getTotalAmount(), 23.5);
}

TEST(Customer, getTotalRenterPointsShouldWork) {
    Customer customer("Olivier");
    EXPECT_EQ(customer.getTotalRenterPoints(), 0);

    std::shared_ptr<RentalMock> ptrRental1 = std::make_shared<RentalMock>(7);
    std::shared_ptr<RentalMock> ptrRental2 = std::make_shared<RentalMock>(2);

    EXPECT_CALL(*ptrRental1, getFrequentRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*ptrRental2, getFrequentRenterPoints()).WillRepeatedly(Return(2));

    customer.addRental(ptrRental1);
    EXPECT_EQ(customer.getTotalRenterPoints(), 1);

    customer.addRental(ptrRental2);
    EXPECT_EQ(customer.getTotalRenterPoints(), 3);
}

TEST(Customer, StatementShouldWork) {
    Customer customer("Olivier");
    std::shared_ptr<RentalMock> ptrRental1 = std::make_shared<RentalMock>(7);
    std::shared_ptr<RentalMock> ptrRental2 = std::make_shared<RentalMock>(5);
    std::shared_ptr<RentalMock> ptrRental3 = std::make_shared<RentalMock>(3);

    EXPECT_CALL(*ptrRental1, getAmount()).WillRepeatedly(Return(9.5));
    EXPECT_CALL(*ptrRental1, getFrequentRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*ptrRental1, getTitleMovie()).WillRepeatedly(Return("Karate Kid"));

    EXPECT_CALL(*ptrRental2, getAmount()).WillRepeatedly(Return(15));
    EXPECT_CALL(*ptrRental2, getFrequentRenterPoints()).WillRepeatedly(Return(2));
    EXPECT_CALL(*ptrRental2, getTitleMovie()).WillRepeatedly(Return("Avengers: Endgame"));

    EXPECT_CALL(*ptrRental3, getAmount()).WillRepeatedly(Return(1.5));
    EXPECT_CALL(*ptrRental3, getFrequentRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*ptrRental3, getTitleMovie()).WillRepeatedly(Return("Snow White"));

    customer.addRental(ptrRental1);
    customer.addRental(ptrRental2);
    customer.addRental(ptrRental3);

    const std::string EXPECTED_RES = "Rental Record for Olivier\n"
                                "\tKarate Kid\t9.5\n"
                                "\tAvengers: Endgame\t15\n"
                                "\tSnow White\t1.5\n"
                                "Amount owed is 26\n"
                                "You earned 4 frequent renter points";

    EXPECT_EQ(customer.statement(), EXPECTED_RES);
}