#include "dfs_finder.h"

namespace component_finder {

void Dfs(const BinaryGrid& grid, std::vector<std::vector<int>>& components, int r0, int c0);

void DfsSpread(const BinaryGrid& grid, std::vector<std::vector<int>>& components, int r, int c, int id) {
  if (r >= 0 && c >= 0 && r < grid.Height() && c < grid.Width() && 
      grid.Get(r, c) && !components[r][c]) {
    components[r][c] = id;
    Dfs(grid, components, r, c);
  }
}

void Dfs(const BinaryGrid& grid, std::vector<std::vector<int>>& components, int r0, int c0) {
  for (int i = -1; i <= 1; i += 2) {
      int r = r0 + i;
      int c = c0;
      DfsSpread(grid, components, r, c, components[r0][c0]);
  }

  for (int j = -1; j <= 1; j += 2) {
      int r = r0;
      int c = c0 + j;
      DfsSpread(grid, components, r, c, components[r0][c0]);
  }
}

std::vector<std::vector<int>> DfsFinder::FindComponents(const BinaryGrid& grid) {
  std::vector<std::vector<int>> components(grid.Height(), std::vector<int>(grid.Width()));
  int id = 0;
  for (int r = 0; r < grid.Height(); ++r) {
    for (int c = 0; c < grid.Width(); ++c) {
      if (grid.Get(r, c) && !components[r][c]) {
        components[r][c] = ++id;
        Dfs(grid, components, r, c);
      }
    }
  }
  return components;
}

}
