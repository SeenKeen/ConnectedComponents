cmake_minimum_required(VERSION 3.21)
project(Cxx11Test)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.79.0 REQUIRED COMPONENTS program_options)

set(CMAKE_CXX_FLAGS "-framework AppKit")
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()


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
                data_structures/compressed_binary_grid.h
                data_structures/compressed_binary_grid.cc
                components_generator.h
                components_generator.cc
                grid_window.h
                grid_window.mm
                growing_connected_component.h
                growing_connected_component.cc
                ns_view_window.h
                ns_view_window.mm
                program_arguments.h
                program_arguments.cc
                util.h
                util.mm)
message(CHECK_START ${Boost_INCLUDE_DIRS})
message(CHECK_START ${Boost_LIBRARIES})
target_link_libraries(Cxx11Test ${Boost_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR})
set_target_properties(Cxx11Test PROPERTIES LINK_FLAGS -Wl,-stack_size,0x10000000)
