#include "growing_connected_component.h"

#include "data_structures/compressed_binary_grid.h"

GrowingConnectedComponent::GrowingConnectedComponent(BinaryGrid& grid, int r, int c) 
: grid_(grid), component_grid_(grid_.Width(), grid_.Height()) {
      border_[kUndefinedDirection] = {
          ComponentCell {
              .r = r, 
              .c = c}};
      component_grid_.Set(r, c, true);
  }

void GrowingConnectedComponent::Grow(int size) {
    assert(size > 0);
    while (size--) {
        Grow();
    }
}

int GrowingConnectedComponent::Size() {
    return size_;
}

void GrowingConnectedComponent::LockBorder() {
  for (auto&& v : border_) {
      for (auto [r, c, d]: v) {
        grid_.Set(r, c, true);
      }
  }
}

void GrowingConnectedComponent::ReleaseBorder() {
  for (auto&& v : border_) {
      for (auto [r, c, d]: v) {
        grid_.Set(r, c, false);
      }
  }
}

void GrowingConnectedComponent::Grow() {
    if (border_.empty()) {
        return;
    }
    if (!std::accumulate(border_.begin(), border_.end(), 0, [] (int sz, const auto& dir_pool) {
      return sz + dir_pool.size();
    })) {
      return;
    }

    int directions_count = border_.size();
    int direction = std::rand() % directions_count;
    while (border_[direction].empty()) {
        direction = std::rand() % directions_count;
    }
    auto& pool = border_[direction];
    int mod = (pool.size() * (pool.size() + 1)) / 2;
    int random_choice = std::rand() % mod;
    int s = 0;
    int index = random_choice;
    for (int i = 1; i <= pool.size(); ++i) {
        if (s + i > random_choice) {
            index = i - 1;
        }
        s += i;
    }
    assert(index != -1);
    auto cell = pool[index];
    //pool.erase(pool.begin() + index);
    std::swap(pool[index], pool.back());
    pool.resize(pool.size() - 1);

  
    for (int r = cell.r - 1; r <= cell.r + 1; r += 2) {
      auto& border_div = border_[DirectionToIndex(r - cell.r, 0)];
      if (r > 0 && r < grid_.Height() && !grid_.Get(r, cell.c) && !component_grid_.Get(r, cell.c)) {
        border_div.push_back(ComponentCell {r, cell.c, cell.bfs_depth + 1});
        component_grid_.Set(r, cell.c, true);
      }
    }
    for (int c = cell.c - 1; c <= cell.c + 1; c += 2) {
      auto& border_div = border_[DirectionToIndex(0, c - cell.c)];
      if (c > 0 && c < grid_.Width() && !grid_.Get(cell.r, c) && !component_grid_.Get(cell.r, c)) {
        border_div.push_back(ComponentCell {cell.r, c, cell.bfs_depth + 1});
        component_grid_.Set(cell.r, c, true);
      }
    }

    //NSLog([[NSString stringWithFormat:@"%d ; %d", cell.r, cell.c] autorelease]);

    bool has_left = !cell.c || grid_.Get(cell.r, cell.c - 1);
    bool has_right = cell.c == grid_.Width() - 1 || grid_.Get(cell.r, cell.c + 1);
    bool has_up = !cell.r || grid_.Get(cell.r - 1, cell.c);
    bool has_down = cell.r == grid_.Height() - 1 || grid_.Get(cell.r + 1, cell.c);
    if (initialized_) {
      assert(has_left || has_right || has_up || has_down);
    }

    grid_.Set(cell.r, cell.c, true);
    size_++;
    initialized_ = true;
}

int GrowingConnectedComponent::DirectionToIndex(int i, int j) {
    assert(std::abs(i) == 1 || !i);
    assert(std::abs(j) == 1 || !j);
    assert(std::abs(i) + std::abs(j) == 1);
    return 2 + i*2 + j;
}
