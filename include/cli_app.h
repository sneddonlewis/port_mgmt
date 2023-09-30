#pragma once
#include <memory>
#include "position_models.h"
#include "position_repository.h"

class CliApp final {
public:
    explicit CliApp(std::shared_ptr<PositionRepository> positionRepository);
    ~CliApp() = default;
    void loop();
private:
    std::shared_ptr<PositionRepository> _positionRepository;

    AddPositionRequest build_add_position_request();
    void add_position_handler();
    void view_positions_handler();
    void print_menu();
    void print_version_info();
};
