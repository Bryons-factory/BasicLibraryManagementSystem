#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "InventoryItem.h"

#include <string>
class Magazine : InventoryItem {
private:
	std::string ISBN;
public:
	//constructors
	Magazine() {}; //default
	Magazine(std::string t, std::string p, std::string a, std::string isbn); //normal
	Magazine(const Magazine& other); //copy
	//destructor
	~Magazine() {};

	//gets
	std::string getISBN() const;
	//sets
	void setISBN(std::string isbn);
};

#endif