#pragma once

#include <vector>

#include "position_models.h"

class PositionRepository final {
public:
    PositionRepository();
    Position OpenPosition(AddPositionRequest positionRequest);
    std::vector<Position> GetAllOpenPositions();
    user_size_t OpenPositionCount();
private:
    std::vector<Position> _positions;
};
