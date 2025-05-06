#include "Admin.h"
#include "User.h"
#include "UserLogin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

// constructor
Admin::Admin() {
	// Initialize member variables if needed
}

// copy constructor
Admin::Admin(const Admin& other) {
	// Copy member variables from the other object
	// Assuming you have member variables to copy
}

// destructor
Admin::~Admin() {
	// Clean up resources if needed
}

// function to add inventory items
void Admin::addInventoryItem(const std::string& title, const std::string& publisher, const std::string& author, const std::string& itemType) {
	std::ofstream inventoryFile("inventory.txt", std::ios::app);
	if (inventoryFile.is_open()) {
		inventoryFile << title << ","
					  << publisher << ","
					  << author << ","
					  << itemType << std::endl;
		inventoryFile.close();
		std::cout << "Inventory item added successfully." << std::endl;
	}
	else {
		std::cerr << "Error opening inventory file." << std::endl;
	}
}

// function to delete inventory items
void Admin::deleteInventoryItem(const std::string& itemName) {
	std::ifstream inventoryFile("inventory.txt");
	std::ofstream tempFile("temp.txt");
	std::string line;
	bool found = false;
	if (inventoryFile.is_open() && tempFile.is_open()) {
		while (std::getline(inventoryFile, line)) {
			if (line.find(itemName) == std::string::npos) {
				tempFile << line << std::endl;
			}
			else {
				found = true;
			}
		}
		inventoryFile.close();
		tempFile.close();
		if (found) {
			remove("inventory.txt");
			rename("temp.txt", "inventory.txt");
			std::cout << "Inventory item deleted successfully." << std::endl;
		}
		else {
			remove("temp.txt");
			std::cout << "Inventory item not found." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening inventory file." << std::endl;
	}
}

// function to add user accounts
void Admin::addUserAccount(const std::string& firstName, const std::string& lastName,
	const std::string& address, const std::string& phoneNumber,
	const std::string& email, const std::string& password, int institutionalID) {
	std::ofstream userFile("users.txt", std::ios::app);
	if (userFile.is_open()) {
		userFile << firstName << "," << lastName << "," << address << ","
			<< phoneNumber << "," << email << "," << password << ","
			<< institutionalID << std::endl;
		userFile.close();
		std::cout << "User account added successfully." << std::endl;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}
}

// function to delete user accounts
void Admin::deleteUserAccount(int institutionalID) {
	std::ifstream userFile("users.txt");
	std::ofstream tempFile("temp.txt");
	std::string line;
	bool found = false;

	if (userFile.is_open() && tempFile.is_open()) {
		while (std::getline(userFile, line)) {
			std::stringstream ss(line);
			std::string token;
			std::vector<std::string> tokens;

			while (std::getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			if (tokens.size() >= 7 && std::stoi(tokens[6]) == institutionalID) {
				found = true; // matched, don't write to temp
			}
			else {
				tempFile << line << std::endl; 
			}
		}
		userFile.close();
		tempFile.close();

		if (found) {
			remove("users.txt");
			rename("temp.txt", "users.txt");
			std::cout << "User account deleted successfully." << std::endl;
		}
		else {
			remove("temp.txt");
			std::cout << "User account not found." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}
}

// function to edit inventory items
void Admin::editInventoryItem(const std::string& itemName, const std::string& newItemName) {
	std::ifstream inventoryFile("inventory.txt");
	std::ofstream tempFile("temp.txt");
	std::string line;
	bool found = false;
	if (inventoryFile.is_open() && tempFile.is_open()) {
		while (std::getline(inventoryFile, line)) {
			if (line.find(itemName) != std::string::npos) {
				line.replace(line.find(itemName), itemName.length(), newItemName);
				found = true;
			}
			tempFile << line << std::endl;
		}
		inventoryFile.close();
		tempFile.close();
		if (found) {
			remove("inventory.txt");
			rename("temp.txt", "inventory.txt");
			std::cout << "Inventory item edited successfully." << std::endl;
		}
		else {
			remove("temp.txt");
			std::cout << "Inventory item not found." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening inventory file." << std::endl;
	}
}

// function to edit user accounts
void Admin::editUserAccount(int institutionalID, const std::string& newFirstName,
	const std::string& newLastName, const std::string& newAddress,
	const std::string& newPhoneNumber, const std::string& newEmail,
	const std::string& newPassword) {
	std::ifstream userFile("users.txt");
	std::ofstream tempFile("temp.txt");
	std::string line;
	bool found = false;
	if (userFile.is_open() && tempFile.is_open()) {
		while (std::getline(userFile, line)) {
			std::stringstream ss(line);
			std::string token;
			std::vector<std::string> tokens;

			while (std::getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			if (tokens.size() >= 7 && std::stoi(tokens[6]) == institutionalID) {
				line = newFirstName + "," + newLastName + "," + newAddress + ","
					+ newPhoneNumber + "," + newEmail + "," + newPassword + ","
					+ std::to_string(institutionalID);
				found = true;
			}
			tempFile << line << std::endl;
		}
		userFile.close();
		tempFile.close();
		if (found) {
			remove("users.txt");
			rename("temp.txt", "users.txt");
			std::cout << "User account edited successfully." << std::endl;
		}
		else {
			remove("temp.txt");
			std::cout << "User account not found." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}
}

// function to view the total number of currently active users
int Admin::viewTotalActiveUsers() {
	std::ifstream userFile("users.txt");
	std::string line;
	int count = 0;
	if (userFile.is_open()) {
		while (std::getline(userFile, line)) {
			count++;
		}
		userFile.close();
		std::cout << "Total active users: " << count << std::endl;
		return count;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
		return -1;
	}
}

// function to search for inventory items by name, ID, keywords, or publisher
void Admin::searchInventoryItem(const std::string& searchTerm) {
	std::ifstream inventoryFile("inventory.txt");
	std::string line;
	bool found = false;
	if (inventoryFile.is_open()) {
		while (std::getline(inventoryFile, line)) {
			if (line.find(searchTerm) != std::string::npos) {
				std::cout << "Found: " << line << std::endl;
				found = true;
			}
		}
		inventoryFile.close();
		if (!found) {
			std::cout << "No inventory items found matching the search term." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening inventory file." << std::endl;
	}
}

// function to search for users by name, ID, or email
void Admin::searchUser(const std::string& searchTerm) {
	std::ifstream userFile("users.txt");
	std::string line;
	bool found = false;
	if (userFile.is_open()) {
		while (std::getline(userFile, line)) {
			if (line.find(searchTerm) != std::string::npos) {
				std::cout << "Found: " << line << std::endl;
				found = true;
			}
		}
		userFile.close();
		if (!found) {
			std::cout << "No users found matching the search term." << std::endl;
		}
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
	}
}

bool Admin::Login() {
	std::string inputEmail;
	std::string inputPassword;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter your email: ";
	std::getline(std::cin, inputEmail);
	std::cout << "Enter your password: ";
	std::getline(std::cin, inputPassword);

	std::ifstream userFile("Admin.txt");
	std::string line;

	if (userFile.is_open()) {
		while (std::getline(userFile, line)) {
			std::stringstream ss(line);
			std::string token;
			std::vector<std::string> tokens;

			while (std::getline(ss, token, ',')) {
				tokens.push_back(token);
			}

			if (tokens.size() >= 2 && tokens[0] == inputEmail && tokens[1] == inputPassword) {
				
				std::cout << "Login successful!\n" << std::endl;
				userFile.close();
				return true;
			}
		}
		userFile.close();
		std::cout << "Invalid email or password. If you are not a Librarian please go else where." << std::endl;
		return false;
	}
	else {
		std::cerr << "Error opening user file." << std::endl;
		return false;
	}
}



