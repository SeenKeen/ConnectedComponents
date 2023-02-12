#include "component_finder/dsu_finder.h"

#include <map>

#include "data_structures/dsu2.h"

namespace component_finder {

std::vector<std::vector<int>> DsuFinder::FindComponents(const BinaryGrid& grid) {
  Dsu2 dsu {grid.Height(), grid.Width()};
  for (int r = 0; r < grid.Height(); ++r) {
    for (int c = 0; c < grid.Width(); ++c) {
      if (!grid.Get(r, c)) {
        continue;
      }
      if (r > 0 && grid.Get(r - 1, c)) {
        dsu.Union({r, c}, {r - 1, c});
      }
      if (c < grid.Width() - 1 && grid.Get(r, c + 1)) {
        dsu.Union({r, c}, {r, c + 1});
      }
    }
  }

  std::vector<std::vector<int>> result(grid.Height(), std::vector<int>(grid.Width()));
  std::map<std::pair<int, int>, int> roots;
  int id = 0;
  for (int r = 0; r < grid.Height(); ++r) {
    for (int c = 0; c < grid.Width(); ++c) {
      auto root = dsu.Root({r, c});
      if (!roots.count(root)) {
        roots[root] = ++id;
      }
      result[r][c] = roots[root];
    }
  }
  return result;
}

}
