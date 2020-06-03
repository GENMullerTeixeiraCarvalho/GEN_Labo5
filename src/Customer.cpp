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
        double thisAmount = 0;

        // determine amounts for each line
        switch ( iter->getMovie().getPriceCode() ) {
            case Movie::REGULAR:
                thisAmount += 2;
                if (iter->getDaysRented() > 2 )
                    thisAmount += (iter->getDaysRented() - 2 ) * 1.5 ;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += iter->getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (iter->getDaysRented() > 3 )
                    thisAmount += (iter->getDaysRented() - 3 ) * 1.5;
                break;
        }

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ((iter->getMovie().getPriceCode() == Movie::NEW_RELEASE )
            && iter->getDaysRented() > 1 ) frequentRenterPoints++;

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