#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <string>

class InventoryItem {
private:
	std::string title;
	std::string publisher;
	std::string author;

public:
	//constructors
	InventoryItem() { }; //default
	InventoryItem(std::string t, std::string p, std::string a); //normal
	InventoryItem(const InventoryItem& other); //copy
	//destructor
	~InventoryItem() { };

	//gets
	std::string getTitle() const;
	std::string getPublisher() const;
	std::string getAuthor() const;
	//sets
	void setTitle(std::string t);
	void setPublisher(std::string p);
	void setAuthor(std::string a);
	//print
	void print() const;
};

#endif