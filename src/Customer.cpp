// Customer.cpp
#include "Rental.h"
#include <string>
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::ostream;
using std::vector;

using namespace std;

Customer::Customer() {}

Customer::Customer( const string& name ) : _name( name ) {}

string Customer::statement()
{
    ostringstream result;
    result << getRentalRecord();
    // add footer lines
    result << "Amount owed is " << getTotalAmount() << "\n";
    result << "You earned " << getTotalRenterPoints()
           << " frequent renter points";
    return result.str();
}

string Customer::getRentalRecord() const {
    ostringstream rentalRecord;

    rentalRecord << "Rental Record for " << getName() << "\n";
    for (const Rental& rental : _rentals) {
        // show figures for this rental
        rentalRecord << "\t" << rental << "\n";
    }
    return rentalRecord.str();
}

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
