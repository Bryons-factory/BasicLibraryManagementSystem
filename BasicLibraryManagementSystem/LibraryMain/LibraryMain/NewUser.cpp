#include "NewUser.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

NewUser::NewUser() {
	std::srand(static_cast<unsigned>(std::time(nullptr)));
}

NewUser::~NewUser() {}

NewUser::NewUser(const NewUser& other) {}

User NewUser::RegisterNewUser() {
	std::string firstName, lastName, address, phoneNumber, email, password;
	int institutionalID;

	User newUserGenerated;

	//Clears newline from interfering with code
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	newUserGenerated.setFirstName(firstName);

	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);
	newUserGenerated.setLastName(lastName);

	std::cout << "Enter your address: ";
	std::getline(std::cin, address);
	newUserGenerated.setAddress(address);

	std::cout << "Enter your phone number: ";
	std::getline(std::cin, phoneNumber);
	newUserGenerated.setPhoneNum(std::stoi(phoneNumber));

	std::cout << "Enter your email: ";
	std::getline(std::cin, email);
	newUserGenerated.setEmail(email);

	std::cout << "Enter your password: ";
	std::getline(std::cin, password);
	newUserGenerated.setPassword(password);

	std::cout << "Enter your institutional ID (staffID, employeeID, studentID): ";
	std::cin >> institutionalID;
	std::cin.ignore();  // Clear newline from buffer
	newUserGenerated.setInstitutionalID(institutionalID);

	// Write to file
	std::ofstream userFile("users.txt", std::ios::app);
	if (userFile.is_open()) {
		userFile << newUserGenerated.getFirstName() << ","
			<< newUserGenerated.getLastName() << ","
			<< newUserGenerated.getAddress() << ","
			<< phoneNumber << ","
			<< newUserGenerated.getEmail() << ","
			<< newUserGenerated.getPassword() << ","
			<< newUserGenerated.getInstitutionalID() << std::endl;

		userFile.close();
		std::cout << "User account created successfully." << std::endl;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}

	return newUserGenerated;
}
