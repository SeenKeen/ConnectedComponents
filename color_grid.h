#pragma once

#include <vector>

#include "color.h"

class ColorGrid {
  public:
    explicit ColorGrid(std::vector<std::vector<Color>> grid);
    Color Get(int i, int j);
    int Rows();
    int Columns();
    ~ColorGrid();

  private:
    std::vector<std::vector<Color>> grid_;
};
