#ifndef BORROWING_H
#define BORROWING_H
#include <iostream>
#include <string>
#include "InventoryItem.h"
//#include "Storage.h"

class Borrowing {
private:
	InventoryItem* userInventory;
	int inventoryElements;

public:
	// Default constructor
	Borrowing() {
		userInventory = new InventoryItem[10];
		inventoryElements = 0;
	}

	// Constructor with parameters
	Borrowing(InventoryItem* inv, int ele) {
		inventoryElements = ele;
		userInventory = new InventoryItem[inventoryElements];
		for (int i = 0; i < inventoryElements; i++) {
			userInventory[i] = inv[i];
		}
	}

	// Copy constructor (deep copy)
	Borrowing(const Borrowing& other) {
		inventoryElements = other.inventoryElements;
		userInventory = new InventoryItem[inventoryElements];
		for (int i = 0; i < inventoryElements; i++) {
			userInventory[i] = other.userInventory[i];
		}
	}

	// Destructor
	~Borrowing() {
		delete[] userInventory;
	}

	// Get inventory item at index
	InventoryItem getInventoryItemAt(int index) const {
		if (index >= 0 && index < inventoryElements) {
			return userInventory[index];
		}
		else {
			std::cout << "Index does not exist\n";
			return InventoryItem(); // Return default
		}
	}

	// Get full inventory pointer
	InventoryItem* getInventory() const {
		return userInventory;
	}

	// Get inventory count
	int getInventoryElements() const {
		return inventoryElements;
	}

	// Set item at index
	void setInventoryItemAt(int index, InventoryItem item) {
		if (index >= 0 && index < inventoryElements) {
			userInventory[index] = item;
		}
		else {
			std::cout << "Index does not exist\n";
		}
	}

	// Replace inventory pointer (shallow copy — use with care)
	void setInventory(InventoryItem* inv) {
		userInventory = inv;
	}

	// Add item to end of inventory
	void addInventoryItem(InventoryItem item) {
		inventoryElements++;
		InventoryItem* oldInv = userInventory;
		userInventory = new InventoryItem[inventoryElements];
		for (int i = 0; i < inventoryElements - 1; i++) {
			userInventory[i] = oldInv[i];
		}
		userInventory[inventoryElements - 1] = item;
		delete[] oldInv;
	}

	// Remove item at index
	void removeInventoryItemAt(int index) {
		if (index >= 0 && index < inventoryElements) {
			for (int i = index; i < inventoryElements - 1; i++) {
				userInventory[i] = userInventory[i + 1];
			}
			InventoryItem* oldInv = userInventory;
			inventoryElements--;
			userInventory = new InventoryItem[inventoryElements];
			for (int i = 0; i < inventoryElements; i++) {
				userInventory[i] = oldInv[i];
			}
			delete[] oldInv;
		}
		else {
			std::cout << "Index does not exist\n";
		}
	}

	// Manually set inventory count
	void setInventoryElements(int ele) {
		inventoryElements = ele;
	}
	
	bool compareDuplicateItems(InventoryItem userInventory, InventoryItem libraryInventory){
		//if(userInventory.getTitle == ) {

		//}
	}
};
#endif