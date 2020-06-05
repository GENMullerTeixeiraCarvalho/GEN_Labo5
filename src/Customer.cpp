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
    for (auto rental = _rentals.begin(); rental != _rentals.end(); ++rental ) {
        // add frequent renter points
        frequentRenterPoints += rental->getFrequentRenterPoints();

        // show figures for this rental
        result << "\t" << *rental << "\n";
        totalAmount += rental->getAmount();
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

Customer::Customer() {}

Customer::Customer( const string& name ) : _name( name ) {}