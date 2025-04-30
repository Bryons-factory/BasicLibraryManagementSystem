#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "InventoryItem.h"

class Storage {
private:
	static int totalUsers;
	//Admin accounts
	//User accounts
	InventoryItem* inventory;
	int inventoryElements;

public:
	//constructors
	Storage() { inventory = new InventoryItem[100]; };
	Storage(InventoryItem* inv, int ele);
	Storage(const Storage& other);
	//destructor
	~Storage() { delete[] inventory; };

	//static methods
	static int getTotalUsers() { return totalUsers; };
	static void setTotalUsers(int users) { totalUsers = users; };
	static void incrementTotalUsers() { totalUsers++; };

	//gets
	InventoryItem getInventoryItemAt(int index) const;
	InventoryItem* getInventory() const;
	int getInventoryElements() const;
	//sets
	void setInventoryItemAt(int index, InventoryItem item); //sets position index to item
	void setInventory(InventoryItem* inv); //sets inventory object
	void addInventoryItem(InventoryItem item); //adds item to back og inventory
	void removeInventoryItemAt(int index); //removes item at index
	void setInventoryElements(int ele);



};


#endif