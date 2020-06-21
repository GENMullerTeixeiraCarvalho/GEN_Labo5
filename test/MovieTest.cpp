#include <gtest/gtest.h>

#include "../src/MoviePriceCode/ChildrenPriceCode.h"
#include "../src/MoviePriceCode/NewReleasePriceCode.h"
#include "../src/MoviePriceCode/RegularPriceCode.h"
#include "../src/Movie.h"

TEST(Movie, setPriceCodeShouldWork){
    Movie myMovie = Movie("TestChildren", ChildrenPriceCode::getPriceCode());
    myMovie.setPriceCode(NewReleasePriceCode::getPriceCode());
    ASSERT_EQ(NewReleasePriceCode::getPriceCode(), myMovie.getPriceCode());
}

TEST(Movie, getPriceCodeShouldWork){
    Movie myMovie = Movie("TestChildren", ChildrenPriceCode::getPriceCode());
    ASSERT_EQ(ChildrenPriceCode::getPriceCode(), myMovie.getPriceCode());
    myMovie.setPriceCode(NewReleasePriceCode::getPriceCode());
    ASSERT_EQ(NewReleasePriceCode::getPriceCode(), myMovie.getPriceCode());
    myMovie.setPriceCode(RegularPriceCode::getPriceCode());
    ASSERT_EQ(RegularPriceCode::getPriceCode(), myMovie.getPriceCode());
}

TEST(Movie, getTitleWork){
    Movie myMovie = Movie("TestChildren", ChildrenPriceCode::getPriceCode());
    ASSERT_EQ(myMovie.getTitle(), "TestChildren");
}
