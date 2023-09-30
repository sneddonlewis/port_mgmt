#include <memory>
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include "cli_app.h"
#include "position_repository.h"

int main() {
    using namespace std;
    auto repo = make_shared<PositionRepository>();
    CliApp app = CliApp{
        repo
    };
    app.loop();
    return 0;
}

