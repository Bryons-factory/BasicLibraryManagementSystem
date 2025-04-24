#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string email;
    std::string password;
    int phoneNum;
    int institutionalID;

    // Future member object:
    // Borrowing borrowed;

public:
    // Default constructor
    User() = default;

    // --- Getters ---
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getAddress() const { return address; }
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    int getPhoneNum() const { return phoneNum; }
    int getInstitutionalID() const { return institutionalID; }

    // --- Setters ---
    void setFirstName(const std::string& newFirstName) { firstName = newFirstName; }
    void setLastName(const std::string& newLastName) { lastName = newLastName; }
    void setAddress(const std::string& newAddress) { address = newAddress; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setPassword(const std::string& newPassword) { password = newPassword; }
    void setPhoneNum(int newPhoneNum) { phoneNum = newPhoneNum; }
    void setInstitutionalID(int newID) { institutionalID = newID; }

    // --- Stub for future method ---
    std::string getBorrowedBook() const {
        return "Book is seen!"; // Stub return value
    }
};

#endif
