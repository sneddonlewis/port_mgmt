// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include <iostream>
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "exampleConfig.h"

void printVersionInfo();

int main() {
    printVersionInfo();
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
