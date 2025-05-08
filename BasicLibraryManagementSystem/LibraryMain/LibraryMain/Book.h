#ifndef BOOK_H
#define BOOK_H

#include "InventoryItem.h"

#include <string>
class Book : InventoryItem {
private:
	std::string ISBN;
	std::string item;
public:
	void itemType() override {
		item = "Book";
	}
	//constructors
	Book() { }; //default
	Book(std::string t, std::string p, std::string a, std::string isbn); //normal
	Book(const Book& other); //copy
	//destructor
	~Book() { };

	//gets
	std::string getISBN() const;
	//sets
	void setISBN(std::string isbn);
	//print
	void print() const;
};

#endif