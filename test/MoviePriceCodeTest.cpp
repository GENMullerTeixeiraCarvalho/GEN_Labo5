#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/MoviePriceCode/MoviePriceCode.h"
#include "../src/MoviePriceCode/ChildrenPriceCode.h"
#include "../src/MoviePriceCode/NewReleasePriceCode.h"
#include "../src/MoviePriceCode/RegularPriceCode.h"

//virtual double getAmount(int nbRentedDays) = 0;
//virtual int getFrequentRenterPoints(int nbRentedDays) = 0;

TEST(ChildrenPriceCode, getAmountShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = ChildrenPriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getAmount(2), 1.5);
    EXPECT_EQ(priceCode->getAmount(4), 3);
}

TEST(ChildrenPriceCode, getFrequentRenterPointsShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = ChildrenPriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getFrequentRenterPoints(1), 1);
    EXPECT_EQ(priceCode->getFrequentRenterPoints(10), 1);
}

TEST(NewReleasePriceCode, getAmountShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = NewReleasePriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getAmount(2), 6);
    EXPECT_EQ(priceCode->getAmount(4), 12);
}

TEST(NewReleasePriceCode, getFrequentRenterPointsShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = NewReleasePriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getFrequentRenterPoints(1), 1);
    EXPECT_EQ(priceCode->getFrequentRenterPoints(10), 2);
}

TEST(RegularPriceCode, getAmountShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = RegularPriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getAmount(2), 2);
    EXPECT_EQ(priceCode->getAmount(4), 5);
}

TEST(RegularPriceCode, getFrequentRenterPointsShouldWork) {
    std::shared_ptr<MoviePriceCode> priceCode = RegularPriceCode::getPriceCode();
    EXPECT_EQ(priceCode->getFrequentRenterPoints(1), 1);
    EXPECT_EQ(priceCode->getFrequentRenterPoints(10), 1);
}