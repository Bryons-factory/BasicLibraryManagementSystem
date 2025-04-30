#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "InventoryItem.h"
#include "User.h"

class Storage {
private:
	static int totalUsers;
	//Admin accounts
	User* userAccounts;
	int numUsers;

	InventoryItem* inventory;
	int inventoryElements;


public:
	//constructors
	Storage() { inventory = new InventoryItem[100]; };
	Storage(InventoryItem* inv, int ele, User* users, int numU);
	Storage(const Storage& other);
	//destructor
	~Storage() { delete[] inventory; };

	//static methods
	static int getTotalUsers() { return totalUsers; };
	static void setTotalUsers(int users) { totalUsers = users; };
	static void incrementTotalUsers() { totalUsers++; };
	static void decrementTotalUsers() { totalUsers--; };

	//gets
	//inv
	InventoryItem getInventoryItemAt(int index) const;
	InventoryItem* getInventory() const;
	int getInventoryElements() const;
	//users
	User getUserAt(int index) const;
	User* getUsers() const;
	int getNumUsers() const;

	//sets
	//inv
	void setInventoryItemAt(int index, InventoryItem item); //sets position index to item
	void setInventory(InventoryItem* inv); //sets inventory object
	void addInventoryItem(InventoryItem item); //adds item to back og inventory
	void removeInventoryItemAt(int index); //removes item at index
	void setInventoryElements(int ele);
	//users
	void setUserAt(int index, User user); //sets position index to item
	void setUserAccounts(User* users); //sets inventory object
	void addUser(User user); //adds item to back og inventory
	void removeUserAt(int index); //removes item at index
	void setNumUsers(int numU);



};


#endif