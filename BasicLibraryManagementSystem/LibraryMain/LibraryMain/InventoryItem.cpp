#include "InventoryItem.h"
#include <iostream>

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