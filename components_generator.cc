#include "components_generator.h"

#include "data_structures/compressed_binary_grid.h"

BinaryGrid GenerateGrid(int width, int height, int components, float max_percent, float alpha) {
  int total_cells = width * height;
  int cells_to_fill = max_percent * total_cells;
  BinaryGrid grid(width, height);

  std::vector<int> slots(components);

  for (int i = 0; i < components; ++i) {
      slots[i] = i;
  }

  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(slots.begin(), slots.end(), g);

  float div_size = static_cast<float>(width) / components;

  auto generate_start = [&] (int i) -> std::pair<int, int> {
      int divison = slots[i];
      int range_start = divison * div_size;
      int rnd_col = range_start + std::rand() % static_cast<int>(div_size);
      int rnd_row = std::rand() % height;
      return {rnd_row, rnd_col};
  };

  float comp_size = static_cast<float>(cells_to_fill)/components;//((alpha - 1)/(std::pow(alpha, components + 1) - 1));
  std::vector<GrowingConnectedComponent> grow_components;
  for (int i = 0; i < components; ++i) {
    auto [r, c] = generate_start(i);
    GrowingConnectedComponent component(grid, r, c);
    component.Grow(comp_size);
    component.LockBorder();
    grow_components.push_back(component);
  }
  std::for_each(grow_components.begin(), grow_components.end(), [] (auto&& component) {
    component.ReleaseBorder();
  });
  return grid;
}
