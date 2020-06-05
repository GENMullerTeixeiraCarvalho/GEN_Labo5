#include "NewReleaseMovie.h"
#include "../MoviePriceCode/NewReleasePriceCode.h"

NewReleaseMovie::NewReleaseMovie(const std::string& title)
: Movie(title, NewReleasePriceCode::getPriceCode()) {}