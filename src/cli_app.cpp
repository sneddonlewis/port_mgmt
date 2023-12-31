#include "cli_app.h"
#include "position_models.h"
#include "iposition_repository.h"
#include "exampleConfig.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <utility>

CliApp::CliApp(std::shared_ptr<IPositionRepo> positionRepository)
    : _positionRepository{std::move(positionRepository)} {}

static auto clear_console() -> void {
    // Unix to clear the screen
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

auto CliApp::loop() -> void {
    clear_console();
    int choice = -1;
    while (choice != 0) {
        print_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_position_handler();
                break;
            case 2:
                view_positions_handler();
                break;
            case 3:
                print_version_info();
                break;
            case 4:
                loadFromFileHandler();
                break;
            case 0:
                std::cout << "Bye" << std::endl;
                break;
            default:
                std::cout << "Unsupported selection" << std::endl;
        }
    }
}

auto CliApp::print_menu() -> void {
    std::cout 
        << "Menu"
        << std::endl
        << "===="
        << std::endl
        << "1. Add"
        << std::endl
        << "2. View"
        << std::endl
        << "3. Info"
        << std::endl
        << "4. Load From CSV"
        << std::endl
        << "0. Exit"
        << std::endl;
}

auto CliApp::print_version_info() -> void {
    clear_console();
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

auto CliApp::add_position_handler() -> void {
    clear_console();
    std::cout << "Add" << std::endl;
    AddPositionRequest request = this->build_add_position_request();
    _positionRepository->OpenPosition(request);
    clear_console();
}

auto CliApp::view_positions_handler() -> void {
    clear_console();
    std::cout << "View" << std::endl;
    std::cout << _positionRepository->OpenPositionCount()
        << " Open Positions"
        << std::endl << std::endl;
    auto open_positions = _positionRepository->GetAllOpenPositions();
    auto print_position = [](Position p) {
        std::string direction = p.is_long ? "Long" : "Short";
        std::time_t time = std::chrono::system_clock::to_time_t(p.open_timestamp);
        std::tm tm = *std::localtime(&time);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        std::string time_str = oss.str();

        std::string timeString = oss.str();
        std::cout << "Ticker: " << p.ticker
            << std::endl
            << "Quantity: " << p.quantity
            << std::endl
            << "Open Price: " << p.open_price
            << std::endl
            << "Direction: " << direction
            << std::endl
            << "Open Time: " << time_str
            << std::endl
            << std::endl;
    };
    std::for_each(
            open_positions.begin(),
            open_positions.end(),
            print_position);
}

auto CliApp::build_add_position_request() -> AddPositionRequest {
    AddPositionRequest request;

    std::cout << "Enter the ticker: ";
    std::cin >> request.ticker;

    std::cout << "Enter the quantity: ";
    std::cin >> request.quantity;

    std::cout << "Enter 1 for a long, 0 for short: ";
    std::cin >> request.is_long;

    std::cout << "Enter the open price: ";
    std::cin >> request.open_price;

    return request;
}

static std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

auto CliApp::loadFromFileHandler() -> void {
    std::string file_path;
    std::cout << "Enter path to CSV file: ";
    std::cin >> file_path;

    std::ifstream myfile;
    myfile.open(file_path);
    std::string myline;
    if ( myfile.is_open() ) {
        while ( myfile ) { // equivalent to myfile.good()
            std::getline (myfile, myline);
            auto parts = split(myline, ',');
            AddPositionRequest add{
                    parts[0],
                    stod(parts[1]),
                    true,
                    stod(parts[2]),
            };
            _positionRepository->OpenPosition(add);
        }
    }
    else {
        std::cout << "Couldn't open file\n";
    }
}
