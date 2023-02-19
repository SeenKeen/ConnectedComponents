#pragma once

#include <set>
#include <utility>
#include <vector>

#include "binary_grid.h"

class CompressedBinaryGrid {
 public:
  explicit CompressedBinaryGrid(const BinaryGrid& grid);

  int Width() const;
  int Height() const;
  bool Get(int row, int column) const;
  void Set(int row, int column, bool value);

 private:
  void SetTrue(int row, int column);
  void SetFalse(int row, int column);

  using Entry = std::pair<int, int>;

  struct CompareIntervalStart {

    bool operator() (const Entry& lhs, const Entry& rhs) const {
      return lhs.second < rhs.second;
    }
  };

 private:
  int height_;
  int width_;

  std::vector<std::set<std::pair<int, int>, CompareIntervalStart>> groups_;
};
