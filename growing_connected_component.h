#pragma once

#include "binary_grid.h"

#include <array>
#include <numeric>

class GrowingConnectedComponent {
  struct ComponentCell;

 public:
  GrowingConnectedComponent(BinaryGrid& grid, int r, int c);
  void Grow(int size);

  int Size();
  void LockBorder();
  void ReleaseBorder();

 private:
  bool initialized_ = false;

  void Grow();

 private:
  struct ComponentCell {
    int r;
    int c;
    int bfs_depth = 0;
  };

 private:

  int DirectionToIndex(int i, int j);

  static constexpr int kUndefinedDirection = 2;

  int size_ = 0;

  BinaryGrid& grid_;
  BinaryGrid component_grid_;
  std::array<std::vector<ComponentCell>, 5> border_;
};
