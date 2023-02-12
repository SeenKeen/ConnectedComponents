#pragma once

#include "connected_components_finder.h"

namespace component_finder {

class DsuFinder : public ConnectedComponentsFinder {
 public:
  std::vector<std::vector<int>> FindComponents(const BinaryGrid& grid) override;

};

}