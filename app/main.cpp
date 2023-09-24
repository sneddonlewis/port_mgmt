// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#include <iostream>
#include <ostream>
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "cli_app.h"
#include "position_repository.h"

int main() {
    PositionRepository positionRepository = PositionRepository{};
    CliApp app = CliApp{
        positionRepository
    };
    app.loop();
    return 0;
}

