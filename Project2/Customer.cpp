#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

Customer::Customer(const string& username, const string& password,
    const string& phonenum, const string& address,
    const BankAccount& bankAccount, const UserRole& role)
    : User(username, password, phonenum, address, bankAccount, CUSTOMER) {

}
//// Implementation of the pure virtual function
//void Customer::displayDetails() const {
//    std::cout << "Customer: " << name << std::endl;
//}

//// Additional member function specific to customers
//void Customer::placeOrder() const {
//    std::cout << name << " is placing an order." << std::endl;
//}
