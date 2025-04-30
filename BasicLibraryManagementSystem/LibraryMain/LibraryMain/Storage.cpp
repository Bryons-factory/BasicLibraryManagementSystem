#include "Storage.h"
#include <iostream>

//constructors
Storage::Storage(InventoryItem* inv, int ele) {
	inventory = inv;
	inventoryElements = ele;
}
Storage::Storage(const Storage& other) {
	inventory = other.getInventory();
	inventoryElements = other.getInventoryElements();
}

//gets
InventoryItem Storage::getInventoryItemAt(int index) const {
	if (index >= 0 && index < inventoryElements) {
		return inventory[index];
	}
	else {
		std::cout << "Index does not exist";
	}
}
InventoryItem* Storage::getInventory() const {
	return inventory;
}
int Storage::getInventoryElements() const {
	return inventoryElements;
}
//sets
void Storage::setInventoryItemAt(int index, InventoryItem item) {
	if (index >= 0 && index < inventoryElements) {
		inventory[index] = item;
	}
	else {
		std::cout << "Index does not exist";
	}
}
void Storage::setInventory(InventoryItem* inv) {
	inventory = inv;
}
void Storage::addInventoryItem(InventoryItem item) {
	inventoryElements++;
	InventoryItem* oldInv = inventory;
	inventory = new InventoryItem[inventoryElements];
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
		InventoryItem* oldInv = inventory;
		inventoryElements--;
		inventory = new InventoryItem[inventoryElements];
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