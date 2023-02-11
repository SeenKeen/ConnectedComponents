#include "color_grid.h"

ColorGrid::ColorGrid(std::vector<std::vector<Color>> grid) : grid_(std::move(grid)) {
    assert(!grid_.empty());
    for (auto&& x : grid_) {
        assert(grid_[0].size() == x.size());
    }
}

Color ColorGrid::Get(int i, int j) {
    return grid_[i][j];
}

int ColorGrid::Rows() {
    return grid_.size();
}

int ColorGrid::Columns() {
    return grid_[0].size();
}

ColorGrid::~ColorGrid() = default;
