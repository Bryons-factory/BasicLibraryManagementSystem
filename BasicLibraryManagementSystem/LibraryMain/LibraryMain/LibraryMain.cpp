// LibraryMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "UserLogin.h"
#include "User.h"
#include "Admin.h"
#include "NewUser.h"
#include "Storage.h"
#include <string>
#include <iostream>
#include "Search.h"
int main()
{
	Admin admin;
	NewUser newUserDatabase;
	UserLogin loginUser;
	User userHolder;
	Storage allData;
	Search selection;

	std::cout << "Welcome to Library Management System!" << std::endl;
	std::cout << "created by Ben, Bryon, Thomas" << std::endl;
	std::cout << "Select an option (1-4) to begin:" << std::endl;
	int sel;
	std::string username;
	std::string password;
	std::string title;
	std::string itemType;

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
				std::cout << "7. View Active Users" << std::endl;
				std::cout << "8. Search Inventory" << std::endl;
				std::cout << "9. Search Users" << std::endl;
				std::cout << "10. Logout" << std::endl;
				int adminSel;
				std::cin >> adminSel;
				switch (adminSel) {
					case 1:
						
						std::cout << "Add Inventory Item" << std::endl;
						std::cout << "Add Inventory Item" << std::endl;
						//admin.addInventoryItem();
						break;
					case 2:
					std::cout << "Delete Inventory Item" << std::endl;
					break;
					case 3:
					std::cout << "Add User Account" << std::endl;
					break;
					case 4:
					std::cout << "Delete User Account" << std::endl;
					break;
					case 5:
					std::cout << "Edit Inventory" << std::endl;
					break;
					case 6:
					std::cout << "Edit User Details" << std::endl;
					break;
					case 7:
					std::cout << "View Active Users" << std::endl;
					break;
					case 8:
					std::cout << "Search Inventory" << std::endl;
					break;
					case 9:
					std::cout << "Search Users" << std::endl;
					break;
					case 10:
					std::cout << "Logout" << std::endl;
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
					std::cout << "\nPlease contact the admin if any item  interests you! Press any key to continue.";
					std::cin >> sel2;
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
			std::cout << "Select an option (1-4) to begin:" << std::endl;
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
