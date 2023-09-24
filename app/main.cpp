// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include <iostream>
#include <ostream>
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "exampleConfig.h"

void printVersionInfo();

struct Position {
    std::string ticker;
    double quantity;
    bool is_long;
    double open_price;
    std::chrono::system_clock::time_point open_timestamp;
};

auto printMenu() {
    std::cout 
        << "1. Add"
        << std::endl
        << "2. View"
        << std::endl
        << "0. Exit"
        << std::endl;
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Add" << std::endl;
                break;
            case 2:
                std::cout << "View" << std::endl;
                break;
            case 0:
                std::cout << "Bye" << std::endl;
                break;
            default:
                std::cout << "Unsupported selection" << std::endl;
        }
    }
    return 0;
}


void printVersionInfo() {
    std::cout
        << "Portfolio Management"
        << std::endl
        << PROJECT_VERSION_MAJOR
        << "."
        << PROJECT_VERSION_MINOR
        << "."
        << PROJECT_VERSION_PATCH
        << "."
        << PROJECT_VERSION_TWEAK
        << std::endl;
    std::system("cat ../LICENSE");
}
