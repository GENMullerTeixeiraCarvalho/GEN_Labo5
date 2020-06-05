#include "RegularMovie.h"

RegularMovie::RegularMovie(const std::string& title)
: Movie(title, RegularPriceCode::getPriceCode()) {}
