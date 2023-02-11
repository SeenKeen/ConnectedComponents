#pragma once

#include <memory>

class ColorGrid;

class GridWindow {
 public:
  explicit GridWindow(std::unique_ptr<ColorGrid> grid);

 private:
  std::unique_ptr<ColorGrid> grid_;
};
