#pragma once

#include <msclr/marshal_cppstd.h>
#include "User.h"

public ref class ManagedUser : public System::IDisposable {
public:
    ManagedUser(User* nativeUser) : nativeUser(nativeUser) {}

    property System::String^ Username {
        System::String^ get() { return gcnew System::String(nativeUser->getUsername().c_str()); }
    }

    property System::String^ Password {
        System::String^ get() { return gcnew System::String(nativeUser->getPassword().c_str()); }
    }

    property System::String^ Phonenum {
        System::String^ get() { return gcnew System::String(nativeUser->getPhonenum().c_str()); }
    }

    property System::String^ Address {
        System::String^ get() { return gcnew System::String(nativeUser->getAddress().c_str()); }
    }

    property System::String^ Role {
        System::String^ get() { return (nativeUser->getRole() == User::ADMIN) ? "Admin" : "Customer"; }
    }

    property double Balance {
        double get() { return nativeUser->getBankAccount().getBalance(); }
    }

    property System::String^ AccountType {
        System::String^ get() { return gcnew System::String(nativeUser->getBankAccount().getAccountType().c_str()); }
    }
    /*
    
    
    property System::String^ BankAccountDetails {
        System::String^ get() { return gcnew System::String((nativeUser->getBankAccount()).toString().c_str()); }
    }
    */
    // Implement IDisposable
    ~ManagedUser() {
        this->!ManagedUser();
    }

    // Finalizer
    !ManagedUser() {
        // Release any resources held by the native User object
        // (Note: Since User is a simple class, you may not need this finalizer)
    }

    //  setBalance method
    void setBalance(double newBalance) {
        nativeUser->getBankAccount().setBalance(newBalance);
    }


private:
    User* nativeUser; // Native C++ User object
};
