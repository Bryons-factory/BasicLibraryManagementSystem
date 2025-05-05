#ifndef SEARCH_H
#define SEARCH_H

#include <string>

class Search {
public:
    void addInventoryItem(const std::string& title, const std::string& publisher, const std::string& author);
    void displayInventory() const;
};

#endif

