//
// Created by Lewis Sneddon on 30/09/2023.
//
#pragma once
#include <vector>
#include "position_models.h"

struct IPositionRepo {
    virtual Position OpenPosition(AddPositionRequest positionRequest) = 0;
    virtual std::vector<Position> GetAllOpenPositions() = 0;
    virtual std::size_t OpenPositionCount() = 0;
    virtual ~IPositionRepo() = default;
};
