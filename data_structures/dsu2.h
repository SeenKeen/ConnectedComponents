#pragma once

#include <vector>

/**
 * 2D Disjoint set union structure
 */
class Dsu2 {
 public:
  explicit Dsu2(int height, int width);

  int Width();
  int Height();

  std::pair<int, int> Root(const std::pair<int, int>& cell);
  void Union(const std::pair<int, int>& a, const std::pair<int, int>& b);
 private:
  int CellToIndex(const std::pair<int, int>& cell);
  std::pair<int, int> IndexToCell(int index);

private:
  int width_;
  int height_;

  std::vector<int> parent_;
};