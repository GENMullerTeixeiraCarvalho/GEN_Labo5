// Customer.cpp
#include "Rental.h"
#include <string>
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (auto iter = _rentals.begin(); iter != _rentals.end(); ++iter ) {
        std::shared_ptr<MoviePriceCode> priceCode = iter->getMovie().getPriceCode();
        double thisAmount = priceCode->getAmount(iter->getDaysRented());

        // add frequent renter points
        frequentRenterPoints += priceCode->getFrequentRenterPoints(iter->getDaysRented());

        // show figures for this rental
        result << "\t" << iter->getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

Customer::Customer() {}

Customer::Customer( const string& name ) : _name( name ) {}