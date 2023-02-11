#pragma once

#include <random>

#include "binary_grid.h"
#include "growing_connected_component.h"

BinaryGrid GenerateGrid(int width, int height, int components, float max_percent = 0.25, float alpha = 1.5);
