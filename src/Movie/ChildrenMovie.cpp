#include "ChildrenMovie.h"
#include "../MoviePriceCode/ChildrenPriceCode.h"

ChildrenMovie::ChildrenMovie(const std::string& title)
: Movie(title, ChildrenPriceCode::getPriceCode()) {}
