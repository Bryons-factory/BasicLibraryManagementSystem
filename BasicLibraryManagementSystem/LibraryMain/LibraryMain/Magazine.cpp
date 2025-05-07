#include "Magazine.h"
#include <iostream>
#include <iomanip>

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

void Magazine::print() const {
	std::cout << "\n"
		<< std::left
		<< std::setw(35) << "Title"
		<< std::setw(25) << "Publisher"
		<< std::setw(25) << "Author"
		<< std::setw(25) << "ISBN" << "\n";
	std::cout << std::string(100, '-') << "\n";

	std::cout << std::left
		<< std::setw(35) << getTitle()
		<< std::setw(25) << getPublisher()
		<< std::setw(25) << getAuthor()
		<< std::setw(25) << ISBN << "\n\n";
}