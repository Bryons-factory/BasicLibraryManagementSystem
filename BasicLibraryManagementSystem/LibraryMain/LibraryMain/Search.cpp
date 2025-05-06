#include "Search.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include <sstream>

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
        std::cout << "\n"
            << std::left
            << std::setw(35) << "Title"
            << std::setw(25) << "Publisher"
            << std::setw(25) << "Author" 
            << std::setw(25) << "Material" << "\n";
        std::cout << std::string(100, '-') << "\n";

        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string title, publisher, author, type;

            std::getline(ss, title, ',');
            std::getline(ss, publisher, ',');
            std::getline(ss, author, ',');
            std::getline(ss, type, ',');

            std::cout << std::left
                << std::setw(35) << title
                << std::setw(25) << publisher
                << std::setw(25) << author
                << std::setw(25) << type << "\n\n";
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open inventory.txt for reading.\n";
    }
}