#include "NewUser.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

NewUser::NewUser() {
	// Constructor implementation
}
NewUser::~NewUser() {
	// Destructor implementation
}
NewUser::NewUser(const NewUser& other) {
	// Copy constructor implementation
	// Assuming you have member variables to copy
	// Copy member variables from the other object
	// firstName = other.firstName;
	// lastName = other.lastName;
	// address = other.address;
	// phoneNumber = other.phoneNumber;
	// email = other.email;
	// password = other.password;
	// institutionalID = other.institutionalID;
}

// Member function to register a new user
void NewUser::RegisterNewUser() {
	std::string firstName, lastName, address, phoneNumber, email, password;
	int institutionalID;
	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter your address: ";
	std::getline(std::cin, address);
	std::cout << "Enter your phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter your email: ";
	std::getline(std::cin, email);
	std::cout << "Enter your password: ";
	std::getline(std::cin, password);
	std::cout << "Enter your institutional ID (staffID, employeeID, studentID): ";
	std::cin >> institutionalID;
	// Store user information in a text file
	/*std::ofstream userFile("users.txt", std::ios::app);
	if (userFile.is_open()) {
		userFile << firstName << "," << lastName << "," << address << ","
			<< phoneNumber << "," << email << "," << password << ","
			<< institutionalID << std::endl;
		userFile.close();
		std::cout << "User account created successfully." << std::endl;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}*/
	// create a new user object
}

// Member function to validate user input
bool NewUser::ValidateInput(const std::string& input) {
	// Implement validation logic here
	// For example, check if the input is not empty
	if (input.empty()) {
		std::cerr << "Invalid input. Please try again." << std::endl;
		return false;
	}
	return true;
}

// Member function to generate a unique library ID
std::string NewUser::GenerateLibraryID() {
	// Implement logic to generate a unique library ID
	// For example, you can use a random number generator or a counter
	int randomID = rand() % 10000; // Generate a random ID between 0 and 9999
	return std::to_string(randomID);
}
