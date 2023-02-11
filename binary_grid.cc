#include "binary_grid.h"

BinaryGrid::BinaryGrid(int width, int height) 
     : grid_(height, std::vector<bool>(width)) {}

int BinaryGrid::Width() const {
    return grid_[0].size();
}

int BinaryGrid::Height() const {
    return grid_.size();
}

bool BinaryGrid::Get(int row, int column) const {
    return grid_[row][column];
}

void BinaryGrid::Set(int row, int column, bool value) {
    grid_[row][column] = value;
}

std::vector<std::vector<Color>> BinaryGrid::Grayscale() {
    std::vector<std::vector<Color>> grid(Height(), std::vector<Color>(Width(), Color::White()));
    for (int i = 0; i < Height(); ++i) {
        for (int j = 0; j < Width(); ++j) {
            if (Get(i, j)) {
              grid[i][j] = {};
            }
        }
    }
    return grid;
}
