#include "util.h"

#include <random>

NSColor* ToNsColor(const Color& color) {
    return [NSColor colorWithCalibratedRed:color.r green:color.g blue:color.b alpha:1];
}

Color GetRandomColor() {
  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> u(0., 1.);
  return {u(gen), u(gen), u(gen)};
}
