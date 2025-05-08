#include "Storage.h"
#include <iostream>

//constructors
Storage::Storage(Book* inv, int ele, User* users, int numU) {
	inventory = inv;
	inventoryElements = ele;
	userAccounts = users;
	int numUsers = numU;
}
Storage::Storage(const Storage& other) {
	inventory = other.getInventory();
	inventoryElements = other.getInventoryElements();
	userAccounts = other.getUsers();
	numUsers = other.getNumUsers();
}

//gets
//inv
Book Storage::getInventoryItemAt(int index) const {
	if (index >= 0 && index < inventoryElements) {
		return inventory[index];
	}
	else {
		std::cout << "Index does not exist";
	}
}
Book* Storage::getInventory() const {
	return inventory;
}
int Storage::getInventoryElements() const {
	return inventoryElements;
}
//users
User Storage::getUserAt(int index) const {
	if (index >= 0 && index < inventoryElements) {
		return userAccounts[index];
	}
	else {
		std::cout << "Index does not exist";
	}
}
User* Storage::getUsers() const {
	return userAccounts;
}
int Storage::getNumUsers() const {
	return numUsers;
}

//sets
//inv
void Storage::setInventoryItemAt(int index, Book item) {
	if (index >= 0 && index < inventoryElements) {
		inventory[index] = item;
	}
	else {
		std::cout << "Index does not exist";
	}
}
void Storage::setInventory(Book* inv) {
	inventory = inv;
}
void Storage::addInventoryItem(Book item) {
	inventoryElements++;
	Book* oldInv = inventory;
	inventory = new Book[inventoryElements];
	for (int i = 0; i < inventoryElements - 1; i++) {
		inventory[i] = oldInv[i];
	}
	inventory[inventoryElements - 1] = item;

}
void Storage::removeInventoryItemAt(int index) {
	if (index >= 0 && index < inventoryElements) {
		for (int i = index; i < inventoryElements - 1; i++) {
			inventory[i] = inventory[i + 1];
		}
		Book* oldInv = inventory;
		inventoryElements--;
		inventory = new Book[inventoryElements];
		for (int i = 0; i < inventoryElements; i++) {
			inventory[i] = oldInv[i];
		}

	}
	else {
		std::cout << "Index does not exist";
	}
}
void Storage::setInventoryElements(int ele) {
	inventoryElements = ele;
}
//users
void Storage::setUserAt(int index, User user) {
	if (index >= 0 && index < numUsers) {
		userAccounts[index] = user;
	}
	else {
		std::cout << "Index does not exist";
	}
}
void Storage::setUserAccounts(User* users) {
	userAccounts = users;
}
void Storage::addUser(User user) {
	numUsers++;
	User* oldUsers = userAccounts;
	userAccounts = new User[numUsers];
	for (int i = 0; i < numUsers - 1; i++) {
		userAccounts[i] = oldUsers[i];
	}
	userAccounts[numUsers - 1] = user;
}
void Storage::removeUserAt(int index) {
	if (index >= 0 && index < numUsers) {
		for (int i = index; i < numUsers - 1; i++) {
			userAccounts[i] = userAccounts[i + 1];
		}
		User* oldUsers = userAccounts;
		numUsers--;
		userAccounts = new User[numUsers];
		for (int i = 0; i < numUsers; i++) {
			userAccounts[i] = oldUsers[i];
		}

	}
	else {
		std::cout << "Index does not exist";
	}
}
void Storage::setNumUsers(int numU) {
	numUsers = numU;
}