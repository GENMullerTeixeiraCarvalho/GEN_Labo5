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
        // add frequent renter points
        frequentRenterPoints += iter->getFrequentRenterPoints();

        // show figures for this rental
        result << "\t" << *iter << "\n";
        totalAmount += iter->getAmount();
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

Customer::Customer() {}

Customer::Customer( const string& name ) : _name( name ) {}