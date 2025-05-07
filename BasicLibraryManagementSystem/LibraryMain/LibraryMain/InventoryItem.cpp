#include "InventoryItem.h"
#include <iostream>
#include <string>
#include <iomanip>

//constructors
InventoryItem::InventoryItem(std::string t, std::string p, std::string a) : title(t), publisher(p), author(a) {

}
InventoryItem::InventoryItem(const InventoryItem& other) : title(other.getTitle()), publisher(other.getPublisher()), author(other.getAuthor()) {

}

//gets
std::string InventoryItem::getTitle() const {
	return title;
}
std::string InventoryItem::getPublisher() const {
	return publisher;
}
std::string InventoryItem::getAuthor() const {
	return author;
}
//sets
void InventoryItem::setTitle(std::string t) {
	title = t;
}
void InventoryItem::setPublisher(std::string p) {
	publisher = p;
}
void InventoryItem::setAuthor(std::string a) {
	author = a;
}
void InventoryItem::print() const {
	std::cout << "\n"
		<< std::left
		<< std::setw(35) << "Title"
		<< std::setw(25) << "Publisher"
		<< std::setw(25) << "Author" << "\n";
	std::cout << std::string(100, '-') << "\n";

	std::cout << std::left
		<< std::setw(35) << title
		<< std::setw(25) << publisher
		<< std::setw(25) << author << "\n\n";
}