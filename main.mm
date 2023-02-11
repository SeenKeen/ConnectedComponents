/* Tiny.m
 * A tiny Cocoa application that creates a window 
 * and then displays graphics in it.
 * IB is not used to create this application.
 */

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <random>
#include <algorithm>
#include <set>
#include <memory>
#include <map>

#include "color_grid.h"
#include "grid_window.h"
#include "components_generator.h"
#include "component_finder/dfs_finder.h"
#include "util.h"

#import <Cocoa/Cocoa.h>


std::vector<std::vector<Color>> AssignColors(std::vector<std::vector<int>> components) {
  std::map<int, Color> colors {{0, Color::White()}};
  std::vector<std::vector<Color>> result(components.size());
  auto it = result.begin();
  for (auto&& row : components) {
    for (auto&& x : row) {
        if (!colors.count(x)) {
            colors[x] = GetRandomColor();
        }
        it->push_back(colors[x]);
    }
    ++it;
  }
  assert(result.size() == 200);
  assert(result[0].size() == 200);
  return result;
}

int main(int argv, char** args)
{
    NSLog(@"Hello");
    // create the autorelease pool
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    // create the application object 
    NSApp = [NSApplication sharedApplication];

    int components = std::stoi(std::string {args[1]});
    auto grid = GenerateGrid(200, 200, components);
    component_finder::DfsFinder finder;
    auto comps = finder.FindComponents(grid);

    // set up the window and drawing mechanism
    // GridWindow window(std::make_unique<ColorGrid>(AssignColors(finder.FindComponents(grid))));
    GridWindow window(std::make_unique<ColorGrid>(AssignColors(comps)));


    // run the main event loop
    [NSApp run];

    // we get here when the window is closed

    [NSApp release];      // release the app 
    [pool release];       // release the pool
    return EXIT_SUCCESS;
    
}