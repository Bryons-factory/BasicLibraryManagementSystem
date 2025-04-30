#include "Book.h"
#include <iostream>

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