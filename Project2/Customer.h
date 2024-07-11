#ifndef DATA_STRUCTURE_PROJECT_CUSTOMER_H
#define DATA_STRUCTURE_PROJECT_CUSTOMER_H

#include "User.h" // Include the base class header
using namespace std;

class Customer : public User {
public:
    Customer(const string& username, const string& password,
        const string& phonenum, const string& address,
        const BankAccount& bankAccount, const UserRole& role);
    // Implementation of the pure virtual function
//    void displayDetails() const override;

    // Additional member function specific to customers
//    void placeOrder() const;

};

#endif //DATA_STRUCTURE_PROJECT_CUSTOMER_H
