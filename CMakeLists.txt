cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)
project(particle_explosion)

# Needed so that cmake uses our find modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

add_subdirectory(main)