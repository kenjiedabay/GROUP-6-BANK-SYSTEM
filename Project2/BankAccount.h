#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "Transaction.h" // Assuming Transaction class is declared in Transaction.h
#include <sstream>
#include <iomanip>
#include "Transaction.h"
#include "LinkedList.cpp"
using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    string accountNumber;
    //    string accountHolderNumber;
    string accountType;
    double balance;


    LinkedList<Transaction> transactions;

public:
    BankAccount(const string& accType, double initBalance);
    // Constructor of BankAccount
    BankAccount() : balance(0.0), accountNumber(generateAccountNumber()) {
        // Initialize an empty transaction list
        transactions = LinkedList<Transaction>();
    }

    const string& getAccountNumber();
    //    const string& getAccountHolderName() const;
    //    void setAccountHolderName(const string& name);
    //    const string& getAccountHolderNumber() const;
    //    void setAccountHolderNumber(const string& number);
    const string& getAccountType();
    void setAccountType(const string& type);
    double getBalance();
    void setBalance(double newBalance);

    void performTransaction(string transactionType, double amount);
    void displayTransactionHistory() const;
    void displayAccountDetails(ostream& out) const;

    // Serialization method
    std::string serialize() const;

    // Deserialization method
    static BankAccount deserialize(const std::string& str);


private:
    static string generateAccountNumber();
};
ostream& operator<<(ostream& os, const BankAccount& account);


#endif // BANKACCOUNT_H