// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
public:
    Customer();
    explicit Customer( const std::string& name );

    void addRental( std::shared_ptr<Rental> arg );
    std::string getName() const;
    std::string statement();
    double getTotalAmount() const;
    int getTotalRenterPoints() const;

private:
    std::string _name;
    std::vector< std::shared_ptr<Rental> > _rentals;

    std::string getRentalRecord() const;
};

inline void Customer::
addRental( const std::shared_ptr<Rental> arg ) { _rentals.push_back( arg ); }

inline std::string Customer::
getName() const { return _name; }

#endif // CUSTOMER_H