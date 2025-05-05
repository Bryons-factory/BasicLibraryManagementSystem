#include "Search.h"
#include <iostream>
#include <fstream>
#include <string>

void Search::addInventoryItem(const std::string& title, const std::string& publisher, const std::string& author) {
    std::ofstream outputFile("inventory.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << title << "," << publisher << "," << author << std::endl;
        outputFile.close();
        std::cout << "Item added to inventory.\n";
    }
    else {
        std::cerr << "Unable to open inventory.txt for writing.\n";
    }
}

void Search::displayInventory() const {
    std::ifstream inputFile("inventory.txt");
    std::string line;

    if (inputFile.is_open()) {
        std::cout << "Inventory contents:\n" << std::endl;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open inventory.txt for reading.\n";
    }
}
