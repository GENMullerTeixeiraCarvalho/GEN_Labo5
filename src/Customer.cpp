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
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for (auto rental = _rentals.begin(); rental != _rentals.end(); ++rental ) {
        // show figures for this rental
        result << "\t" << *rental << "\n";
    }
    // add footer lines
    result << "Amount owed is " << getTotalAmount() << "\n";
    result << "You earned " << getTotalRenterPoints()
           << " frequent renter points";
    return result.str();
}

Customer::Customer() {}

Customer::Customer( const string& name ) : _name( name ) {}

double Customer::getTotalAmount() const {
    double totalAmount = .0;
    for (const Rental& rental : _rentals) {
        totalAmount += rental.getAmount();
    }
    return totalAmount;
}

int Customer::getTotalRenterPoints() const {
    int totalPoints = 0;
    for (const Rental& rental : _rentals) {
        totalPoints += rental.getFrequentRenterPoints();
    }
    return totalPoints;
}
