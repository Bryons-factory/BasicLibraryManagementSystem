// thall
#include "UserLogin.h"  
#include "User.h"

#include <iostream>  
#include <string>  
#include <fstream>  
#include <sstream>   
#include <vector>


// Default constructor
UserLogin::UserLogin() {
	User dummyUser;

	// Initialize member variables with dummy values using User's getters
	// if get is empty return dummy information otherwise get information from User
	dummyUser.setFirstName("John");
	dummyUser.setLastName("Doe");
	dummyUser.setAddress("123 Main St");
	dummyUser.setPhoneNum(1234567890);
	dummyUser.setEmail("john.doe@example.com");
	dummyUser.setPassword("password123");
	dummyUser.setInstitutionalID(1001);
}


// destructor
UserLogin::~UserLogin() {
	// Clean up resources if needed
}

// function to prompt a user login
bool UserLogin::Login(User& outUser) {
	std::string inputEmail;
	std::string inputPassword;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter your email: ";
	std::getline(std::cin, inputEmail);
	std::cout << "Enter your password: ";
	std::getline(std::cin, inputPassword);

	std::ifstream userFile("users.txt");
	std::string line;

	if (userFile.is_open()) {
		while (std::getline(userFile, line)) {
			std::stringstream ss(line);
			std::string token;
			std::vector<std::string> tokens;

			while (std::getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			if (tokens.size() >= 7 && tokens[4] == inputEmail && tokens[5] == inputPassword) {
				outUser.setFirstName(tokens[0]);
				outUser.setLastName(tokens[1]);
				outUser.setAddress(tokens[2]);
				outUser.setPhoneNum(std::stoi(tokens[3]));
				outUser.setEmail(tokens[4]);
				outUser.setPassword(tokens[5]);
				outUser.setInstitutionalID(std::stoi(tokens[6]));

				std::cout << "Login successful!\n" << std::endl;
				userFile.close();
				return true;
			}
		}
		userFile.close();
		std::cout << "Invalid email or password. Please try again." << std::endl;
		return false;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
		return false;
	}
}



// function to log out a user
void UserLogin::Logout() { // do we need this?
	std::cout << "Logging out..." << std::endl;
	// Perform any necessary cleanup or state changes
}

// function to print user summary
void UserLogin::PrintUserSummary(User curUser) const {
	std::cout << "User Summary:" << std::endl;
	std::cout << "First Name: " << curUser.getFirstName() << std::endl;
	std::cout << "Last Name: " << curUser.getLastName() << std::endl;
	std::cout << "Address: " << curUser.getAddress() << std::endl;
	std::cout << "Phone Number: " << curUser.getPhoneNum() << std::endl;
	std::cout << "Email: " << curUser.getEmail() << std::endl;
	std::cout << "Password: " << curUser.getPassword() << std::endl;
	std::cout << "Institutional ID: " << curUser.getInstitutionalID() << std::endl;
}



