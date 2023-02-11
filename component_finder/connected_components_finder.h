#include <vector>
#include <utility>

#include "binary_grid.h"

class ConnectedComponentsFinder {
  public:
    virtual std::vector<std::vector<int>> FindComponents(const BinaryGrid& grid) = 0;
};
