#ifndef DATA_STRUCTURE_PROJECT_USER_H
#define DATA_STRUCTURE_PROJECT_USER_H

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;


class User {

public:
    static int nextuID;

    enum UserRole {
        ADMIN,
        CUSTOMER
    };

    User(const string& username, const string& password,
        const string& phonenum, const string& address,
        const BankAccount& bankAccount, const UserRole& role);

    User(UserRole role, const string& fname, const string& lname, const string& email,
        const string& password, const string& phoneNum, double initBalance, string Username);

    User() : Fname(""), Lname(""), Email(""), Password(""), phonenum("") {
        //       type = userType;
        //       uID = generateUserID();



    }


    void setUserId(const std::string& newUserId);
    // Getters
protected: std::string userid;

public:
    const string& getUsername() const;
    const string& getPassword() const;
    const string& getPhonenum() const;
    const string& getAddress() const;
    BankAccount& getBankAccount();
    UserRole getRole() const;

    // Setters
    void setUsername(const string& newUsername);
    void setPassword(const string& newPassword);
    void setPhonenum(const string& newPhonenum);
    void setAddress(const string& newAddress);
    void setBankAccount(const BankAccount& newBankAccount);
    void setRole(UserRole newRole);

    // Helper function to serialize BankAccount
    std::string serializeBankAccount() const;

    // Helper function to deserialize BankAccount
    static BankAccount deserializeBankAccount(const std::string& str);

    // Serialize function
    std::string serialize() const;

    // Deserialize function
    static User deserialize(const std::string& str);
    string generateUserID();



protected:
    string username;
    string Password;
    string phonenum;
    string address;
    string uID;
    string Email;
    BankAccount bankAccount;
    string Fname;
    string Lname;
    UserRole role;

    void displayUserDetails(ostream& out) const;

    friend ostream& operator<<(ostream& os, const User& user);
};

#endif //DATA_STRUCTURE_PROJECT_USER_H