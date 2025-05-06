// LibraryMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "UserLogin.h"
#include "User.h"
#include "Admin.h"
#include "NewUser.h"
#include "Storage.h"
#include <string>
#include <iostream>
#include "Search.h"
#include "Book.h"

int main()
{
	Admin admin;
	NewUser newUserDatabase;
	UserLogin loginUser;
	User userHolder;
	Storage allData;
	Search selection;
	Book book;


	std::cout << "Welcome to Library Management System!" << std::endl;
	std::cout << "created by Ben, Bryon, Thomas" << std::endl;
	std::cout << "Select an option (1-4) to begin:" << std::endl;
	int sel, adminSel, institutionalID;
	std::string username;
	std::string password;
	std::string title, publisher, author, firstName, lastName, address,
				phoneNumber;
	std::string itemType, newItemType;

	while (true)
	{
		std::cout << "1. Register New Users" << std::endl;
		std::cout << "2. Admin (Librarian) Login" << std::endl;
		std::cout << "3. User Login" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cin >> sel;
		switch (sel) {
		case 1:
			std::cout << "Register New Users" << std::endl;
			allData.addUser(newUserDatabase.RegisterNewUser());
			break;
		case 2:
			std::cout << "Admin (Librarian) Login" << std::endl;

			if(admin.Login())
			{
			// options for admin assuming correct login
				std::cout << "1. Add Inventory Item" << std::endl;
				std::cout << "2. Delete Inventory Item" << std::endl;
				std::cout << "3. Add User Account" << std::endl;
				std::cout << "4. Delete User Account" << std::endl;
				std::cout << "5. Edit Inventory" << std::endl;
				std::cout << "6. Edit User Details" << std::endl;
				std::cout << "6. View Active Users" << std::endl;
				std::cout << "7. Search Inventory" << std::endl;
				std::cout << "8. Search Users" << std::endl;
				std::cout << "9. Logout" << std::endl;
				int adminSel;
				std::cin >> adminSel;
				switch (adminSel) {
					case 1:
						
						std::cout << "Add Inventory Item" << std::endl;
						std::cout << "What is the title of the item you would like to add?" << std::endl;
						std::cin >> title;

						std::cout << "What is the publisher of the item you would like to add?" << std::endl;
						std::cin >> publisher;

						std::cout << "What is the author of the item you would like to add?" << std::endl;
						std::cin >> author;
						
						std::cout << "What is type of media are you adding(book, magazine, or other)?" << std::endl;
						std::cin >> itemType;

						admin.addInventoryItem(title,publisher,author,itemType);

						std::cout << "You've succesfully added an item to our database" << std::endl;
						break;
					case 2:
						std::cout << "Delete Inventory Item" << std::endl;
						std::cout << "What is the title of the item you would like to delete?" << std::endl;
						std::cin >> title;

						admin.deleteInventoryItem(title);

						std::cout << "You've succesfully deleted an item to our database!" << std::endl;
						break;
					case 3:
						std::cout << "Add User Account" << std::endl;

						std::cout << "Please enter the first name of the user to be added: ";
						std::cin >> firstName;

						std::cout << "Please enter the last name of the user to be added: ";
						std::cin >> lastName;

						std::cin.ignore(); // Clear newline from buffer before getline

						std::cout << "Please enter the address: ";
						std::getline(std::cin, address);

						std::cout << "Please enter the phone number: ";
						std::getline(std::cin, phoneNumber);

						std::cout << "Please enter the email: ";
						std::getline(std::cin, username);

						std::cout << "Please enter the password: ";
						std::getline(std::cin, password);

						std::cout << "Please enter the institutional ID: ";
						std::cin >> institutionalID;

						admin.addUserAccount(firstName, lastName, address, phoneNumber, username, password, institutionalID);
						break;
					case 4:
						std::cout << "Delete User Account" << std::endl;

						std::cout << "Please enter the institutional ID of user to be deleted ";
						std::cin >> institutionalID;
						admin.deleteUserAccount(institutionalID);
						break;
					case 5:
						std::cout << "Edit Inventory" << std::endl;
						std::cout << "Please enter the value you would like to be changed in our library database."  << std::endl;
						std::cin >> itemType;
						std::cout << "Please enter the replacement value you would like to be placed in our library database." << std::endl;
						std::cin >> newItemType;
						admin.editInventoryItem(itemType, newItemType);
						break;
					case 6:
						std::cout << "View Active Users" << std::endl;
						admin.viewTotalActiveUsers();
						break;
					case 7:
						std::cout << "Search Inventory" << std::endl;
						std::cout << "Please enter the value you would like to search for and we will return any matches" << std::endl;
						std::cin >> itemType;
						admin.searchInventoryItem(itemType);
						break;
					case 8:
						std::cout << "Search Users" << std::endl;
						std::cout << "Please enter the user you would like to search for and we will return any matches" << std::endl;
						std::cin >> itemType;
						admin.searchUser(itemType);
						break;
					case 9:
						std::cout << "Logout" << std::endl;
						continue;
						break;
					default:
						std::cout << "Invalid selection. Please try again." << std::endl;
						break;
				}
			}

			break;
		case 3:
			
			loginUser.Login(userHolder);

			loginUser.PrintUserSummary(userHolder);
			int sel2;
			std::cout << "\nSelect 1 to search our selection, else press any other key";
			std::cin >> sel2;
			while(sel2== 1){
				switch(sel2)
					case 1:
					selection.displayInventory();
					std::cout << "\nPlease contact the admin if any item  interests you! Press any integer key and press enter to continue.";
					std::cin >> sel2;
					std::cout << "\nSelect an option (1-4) to begin:";
					std::cin >> sel;
					break;
			}
			std::cout << std::endl;

			break;


			break;
		case 4:
			std::cout << "Exit. Thank you for using the Basic Library Management System!" << std::endl;
			return 0;
			break;
		default:
			std::cout << "Invalid selection. Please try again." << std::endl;
			std::cout << "Select an option (1-4) and press enter to begin:" << std::endl;
			break;
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
