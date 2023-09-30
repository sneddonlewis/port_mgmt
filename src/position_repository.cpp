#include "position_repository.h"
#include "position_models.h"
#include <chrono>

PositionRepository::PositionRepository() 
    : _positions{}
{}

auto PositionRepository::OpenPosition(AddPositionRequest request) -> Position {
    Position entity = Position{
        request.ticker,
        request.quantity,
        request.is_long,
        request.open_price,
        std::chrono::system_clock::now(),
    };
    _positions.push_back(entity);
    return entity;
}

auto PositionRepository::GetAllOpenPositions() -> std::vector<Position> {
    return _positions;
}

auto PositionRepository::OpenPositionCount() -> std::size_t {
    return _positions.size();
}
