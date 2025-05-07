#include "Book.h"
#include <iostream>
#include <iomanip>

//constructors
Book::Book(std::string t, std::string p, std::string a, std::string isbn) : InventoryItem(t, p, a), ISBN(isbn) {

}
Book::Book(const Book& other) : InventoryItem(other.getTitle(), other.getPublisher(), other.getAuthor()), ISBN(other.getISBN()) {

}

//gets
std::string Book::getISBN() const {
	return ISBN;
}
//sets
void Book::setISBN(std::string isbn) {
	ISBN = isbn;
}

void Book::print() const {
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