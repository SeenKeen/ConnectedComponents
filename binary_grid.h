#pragma once

#include <vector>

#include "color.h"

class BinaryGrid {
 public:
  BinaryGrid(int width, int height);

  int Width() const;
  int Height() const;
  bool Get(int row, int column) const;
  void Set(int row, int column, bool value);
  std::vector<std::vector<Color>> Grayscale();

 private:
  std::vector<std::vector<bool>> grid_;
};
