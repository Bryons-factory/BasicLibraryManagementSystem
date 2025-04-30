// thall
#include "UserLogin.h"  
#include "User.h"

#include <iostream>  
#include <string>  
#include <fstream>  
#include <sstream>   


// constructor
UserLogin::UserLogin() {
	// Initialize member variables if needed
}

// Default constructor
UserLogin::UserLogin() {
	User dummyUser;

	// Initialize member variables with dummy values using User's getters
	// if get is empty return dummy information otherwise get information from User
	firstName = dummyUser.getFirstName().empty() ? "John" : dummyUser.getFirstName();
	lastName = dummyUser.getLastName().empty() ? "Doe" : dummyUser.getLastName();
	address = dummyUser.getAddress().empty() ? "123 Main St" : dummyUser.getAddress();
	phoneNumber = dummyUser.getPhoneNum() == 0 ? 1234567890 : dummyUser.getPhoneNum();
	email = dummyUser.getEmail().empty() ? "john.doe@example.com" : dummyUser.getEmail();
	password = dummyUser.getPassword().empty() ? "password123" : dummyUser.getPassword();
	institutionalID = dummyUser.getInstitutionalID() == 0 ? 1001 : dummyUser.getInstitutionalID();
}


// copy constructor
UserLogin::UserLogin(const UserLogin& other) {
	// Copy member variables from the other object
	firstName = other.firstName;
	lastName = other.lastName;
	address = other.address;
	phoneNumber = other.phoneNumber;
	email = other.email;
	password = other.password;
	institutionalID = other.institutionalID;
}

// destructor
UserLogin::~UserLogin() {
	// Clean up resources if needed
}

// function to prompt a user login
bool UserLogin::Login() {
	std::string inputEmail;
	std::string inputPassword;
	std::cout << "Enter your email: ";
	std::getline(std::cin, inputEmail);
	std::cout << "Enter your password: ";
	std::getline(std::cin, inputPassword);
	// Check if the email and password match
	if (inputEmail == email && inputPassword == password) {
		std::cout << "Login successful!" << std::endl;
		return true;
	}
	else {
		std::cout << "Invalid email or password. Please try again." << std::endl;
		return false;
	}
}

// function to log out a user
void UserLogin::Logout() { // do we need this?
	std::cout << "Logging out..." << std::endl;
	// Perform any necessary cleanup or state changes
}

// function to print user summary
void UserLogin::PrintUserSummary() const {
	std::cout << "User Summary:" << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Email: " << email << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Institutional ID: " << institutionalID << std::endl;
}



