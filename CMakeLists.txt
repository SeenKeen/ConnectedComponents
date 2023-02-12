cmake_minimum_required(VERSION 3.21)
project(Cxx11Test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-framework AppKit")

add_executable(Cxx11Test 
                main.mm 
                binary_grid.h
                binary_grid.cc
                color.h
                color.cc
                color_grid.h
                color_grid.cc
                component_finder/connected_components_finder.h
                component_finder/dfs_finder.h
                component_finder/dfs_finder.cc
                component_finder/dsu_finder.h
                component_finder/dsu_finder.cc
                data_structures/dsu2.h
                data_structures/dsu2.cc
                components_generator.h
                components_generator.cc
                grid_window.h
                grid_window.mm
                growing_connected_component.h
                growing_connected_component.cc
                ns_view_window.h
                ns_view_window.mm
                util.h
                util.mm)

include_directories(${PROJECT_SOURCE_DIR})
set_target_properties(Cxx11Test PROPERTIES LINK_FLAGS -Wl,-stack_size,0x10000000)
