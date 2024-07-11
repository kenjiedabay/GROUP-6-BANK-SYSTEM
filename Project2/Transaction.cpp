#include "Transaction.h"
#include <sstream>



Transaction::Transaction(std::string transactionType, double transactionAmount)
    : type(transactionType), amount(transactionAmount) {

    // Get current date
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date = std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + "/" + std::to_string(1900 + ltm->tm_year);
}

// Implement getters
std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getDate() const {
    return date;
}

std::ostream& operator<<(std::ostream& os, const Transaction& transaction) {
    os << "--------------------------------------\n";
    os << "              TRANSACTION              \n";
    os << "--------------------------------------\n";
    os << "Date: " << transaction.getDate() << "\n";
    if (transaction.getType() == "deposit") {
        os << "Type:    Deposit\n";
    }
    else if (transaction.getType() == "withdraw") {
        os << "Type:    Withdrawal\n";
    }
    else if (transaction.getType() == "inquiry") {
        os << "Type:    Balance Inquiry\n";
    }
    else {
        os << "Type:    Unknown\n"; // Handle the case when the type is none of the expected values
    }
    os << "Amount:  $" << std::fixed << std::setprecision(2) << transaction.getAmount() << "\n";
    os << "--------------------------------------\n";
    os << "\n";
    os << "--------------------------------------\n";
    return os;
}

Transaction Transaction::deserialize(const std::string& str) {
    std::istringstream iss(str);
    Transaction transaction;
    char pipe;

    if (std::getline(iss, transaction.type, '|') &&
        iss >> transaction.amount >> pipe) {
        std::getline(iss, transaction.date);
    }

    return transaction;
}

// Serialization method for Transaction
std::string Transaction::serialize() const {
    return type + "|" + std::to_string(amount) + "|" + date;

}