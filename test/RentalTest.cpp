#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>

#include "../src/MoviePriceCode/ChildrenPriceCode.h"
#include "../src/Movie.h"
#include "../src/Rental.h"

using ::testing::Return;

class MoviePriceCodeMock : public MoviePriceCode{
public:
    MOCK_METHOD(double, getAmount, (int nbRentedDays));
    MOCK_METHOD(int, getFrequentRenterPoints, (int nbRentedDays));
};

class MovieMock : public Movie{
public:
    MovieMock( const std::string& title, std::shared_ptr<MoviePriceCode> priceCode ) : Movie(title, priceCode) {}
    MOCK_METHOD(std::string, getTitle, (), (const));
    MOCK_METHOD(void, setPriceCode, (std::shared_ptr<MoviePriceCode> arg));
    MOCK_METHOD(std::shared_ptr<MoviePriceCode>, getPriceCode, (), (const));
};

TEST(Rental, getAmountShouldWork){
    std::shared_ptr<MoviePriceCodeMock> ptrMoviePriceCodeMock = std::make_shared<MoviePriceCodeMock>();
    std::shared_ptr<MovieMock> ptrMovieMock = std::make_shared<MovieMock>("MyTitle", ptrMoviePriceCodeMock);
    const int nbRentedDays = 3;

    EXPECT_CALL(*ptrMovieMock, getPriceCode()).WillRepeatedly(Return(ptrMoviePriceCodeMock));
    EXPECT_CALL(*ptrMoviePriceCodeMock, getAmount(nbRentedDays)).WillRepeatedly(Return(nbRentedDays));

    Rental rental = Rental(*ptrMovieMock, nbRentedDays);

    ASSERT_EQ(rental.getAmount(), nbRentedDays);
}

TEST(Rental, getFrequentPointsShouldWork){
    std::shared_ptr<MoviePriceCodeMock> ptrMoviePriceCodeMock = std::make_shared<MoviePriceCodeMock>();
    std::shared_ptr<MovieMock> ptrMovieMock = std::make_shared<MovieMock>("MyTitle", ptrMoviePriceCodeMock);
    const int nbRentedDays = 3;

    EXPECT_CALL(*ptrMovieMock, getPriceCode()).WillRepeatedly(Return(ptrMoviePriceCodeMock));
    EXPECT_CALL(*ptrMoviePriceCodeMock, getFrequentRenterPoints(nbRentedDays)).WillRepeatedly(Return(1));

    Rental rental = Rental(*ptrMovieMock, nbRentedDays);

    ASSERT_EQ(rental.getFrequentRenterPoints(), 1);
}