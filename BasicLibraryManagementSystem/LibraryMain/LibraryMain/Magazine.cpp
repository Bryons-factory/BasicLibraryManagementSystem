#include "Magazine.h"
#include <iostream>

//constructors
Magazine::Magazine(std::string t, std::string p, std::string a, std::string isbn) : InventoryItem(t, p, a), ISBN(isbn) {

}
Magazine::Magazine(const Magazine& other) : InventoryItem(other.getTitle(), other.getPublisher(), other.getAuthor()), ISBN(other.getISBN()) {

}

//gets
std::string Magazine::getISBN() const {
	return ISBN;
}
//sets
void Magazine::setISBN(std::string isbn) {
	ISBN = isbn;
}