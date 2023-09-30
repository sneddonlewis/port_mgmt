#pragma once

#include <vector>

#include "iposition_repository.h"
#include "position_models.h"

class PositionRepository final : public IPositionRepo {
public:
    PositionRepository();
    Position OpenPosition(AddPositionRequest positionRequest) override;
    std::vector<Position> GetAllOpenPositions() override;
    user_size_t OpenPositionCount() override;
private:
    std::vector<Position> _positions;
};
