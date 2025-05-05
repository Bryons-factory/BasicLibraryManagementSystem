// header file for the admin class
// thall
/*****************************************
* class description:
* Admin class is responsible for administering the system
* (acting as the librarian). by adding or removing inventory items
* and creating user accoutns. the login credentials for librarians
* are stored in the librarians.txt file. No class has the capability to
* create a librarian account, instead the librarian's name and password
* must be manually inserted into librarians.txt. initially, the first
* names of you and your group members, along with their corresponding
* passwords, will be stored in this file.
*
* functional requirements:
* a) the Admin can add or delete inventory items
* b) all book and magazine information must be stored
* in a text file named book.txt
* c) the Admin can add or delete user accounts
* d) all user information must be stored in a text file,
* which will later be used for user authentication
* e) the Admin can edit inventory and user details
* f) the Admin can view the total number of currently active
* users in the system
* g) the Admin can search for inventory items and users by name, ID,
* keywords, or publisher
*
*
*****************************************/

#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Admin {
public:
	// Storage instanceOfStorage;
	// add instance of search function (from Storage?)
	// Constructor
	Admin();
	// Destructor
	~Admin();
	// Copy constructor
	Admin(const Admin& other);

	// Function to add inventory items
	void addInventoryItem(const std::string& itemName, const std::string& itemType);
	// Function to delete inventory items
	void deleteInventoryItem(const std::string& itemName);
	// Function to add user accounts
	void addUserAccount(const std::string& firstName, const std::string& lastName,
		const std::string& address, const std::string& phoneNumber,
		const std::string& email, const std::string& password, int institutionalID);
	// Function to delete user accounts
	void deleteUserAccount(int institutionalID);
	// Function to edit inventory items
	void editInventoryItem(const std::string& itemName, const std::string& newItemName);
	// Function to edit user accounts
	void editUserAccount(int institutionalID, const std::string& newFirstName,
		const std::string& newLastName, const std::string& newAddress,
		const std::string& newPhoneNumber, const std::string& newEmail,
		const std::string& newPassword);
	// Function to view total number of active users
	int viewTotalActiveUsers();
	// Function to search for inventory items
	void searchInventoryItem(const std::string& searchTerm);
	// Function to search for users
	void searchUser(const std::string& searchTerm);
	//Function to login to Admin Account
	bool Login();
};

#endif // ADMIN_H
