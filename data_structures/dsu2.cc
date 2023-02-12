#include "data_structures/dsu2.h"

Dsu2::Dsu2(int height, int width) : height_(height), width_(width), parent_(Height() * Width(), -1) {}

int Dsu2::CellToIndex(const std::pair<int, int>& cell) {
  int row = cell.first;
  int col = cell.second;
  return Width() * row + col;
}

std::pair<int, int> Dsu2::IndexToCell(int index) {
  return {index / Width(), index % Width()};
}

std::pair<int, int> Dsu2::Root(const std::pair<int, int>& cell) {
  int index = CellToIndex(cell);
  int j = index;
  while (parent_[j] != -1) {
    j = parent_[j];
    parent_[index] = j;
  }
  return IndexToCell(j);
}

void Dsu2::Union(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  int root_a = CellToIndex(Root(a));
  int root_b = CellToIndex(Root(b));
  if (root_b == root_a) {
    return;
  }
  parent_[root_b] = root_a;
}

int Dsu2::Width() {
  return width_;
}

int Dsu2::Height() {
  return height_;
}
