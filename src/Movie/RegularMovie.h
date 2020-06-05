#ifndef GEN_LABO5_REGULARMOVIE_H
#define GEN_LABO5_REGULARMOVIE_H

#include "Movie.h"
#include "../MoviePriceCode/RegularPriceCode.h"

class RegularMovie : public Movie {
public:
    explicit RegularMovie(const std::string& title);
};


#endif //GEN_LABO5_REGULARMOVIE_H
