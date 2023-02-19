#include "data_structures/compressed_binary_grid.h"

CompressedBinaryGrid::CompressedBinaryGrid(const BinaryGrid& grid) 
  : height_(grid.Height()), width_(grid.Width()), groups_(height_) {
  for (int r = 0; r < grid.Height(); ++r) {
    for (int c = 0; c < grid.Width(); ++c) {
      if (grid.Get(r, c)) {
        Set(r, c, true);
      }
    }
  }
}

int CompressedBinaryGrid::Height() const {
  return height_;
}

int CompressedBinaryGrid::Width() const {
  return width_;
}

bool CompressedBinaryGrid::Get(int row, int column) const {
  auto it = groups_[row].upper_bound({column,column});
  if (it != groups_[row].end()) {
    return it->first <= column;
  }
  return false;
}

void CompressedBinaryGrid::SetTrue(int row, int column) {
  if (!Get(row, column)) {
    auto it = groups_[row].upper_bound({column,column});
    if (it != groups_[row].end() && it->first == column + 1) {
      auto it_prev = std::prev(it);
      if (it != groups_[row].begin() && it_prev->second == column) {
        int a = it_prev->first;
        int b = it_prev->second;
        groups_[row].erase(it);
        groups_[row].erase(it_prev);
        groups_[row].emplace(a, b);
      } else {
        int a = column;
        int b = it->second;
        groups_[row].erase(it);
        groups_[row].emplace(a, b);
      }
    } else {
      groups_[row].emplace(column, column+1);
    }
  }
}

void CompressedBinaryGrid::SetFalse(int row, int column) {
  if (Get(row, column)) {
    auto it = groups_[row].upper_bound({column,column});
    if (it->first == column) {
      int a = it->first + 1;
      int b = it->second;
      groups_[row].erase(it);
      if (a < b) {
        groups_[row].emplace(a, b);
      }
    } else {
      int a1 = it->first;
      int b1 = column;
      int a2 = column + 1;
      int b2 = it->second;
      groups_[row].erase(it);
      if (a1 < b1) {
        groups_[row].emplace(a1, b1);
      }
      if (a2 < b2) {
        groups_[row].emplace(a2, b2);
      }
    }
  }
}

void CompressedBinaryGrid::Set(int row, int column, bool value) {
  if (value) {
    SetTrue(row, column);
  } else {
    SetFalse(row, column);
  }
}
