#pragma once

#include <string>
#include <chrono>

struct Position {
    std::string ticker;
    double quantity;
    bool is_long;
    double open_price;
    std::chrono::system_clock::time_point open_timestamp;
};

struct AddPositionRequest {
    std::string ticker;
    double quantity;
    bool is_long;
    double open_price;
};

