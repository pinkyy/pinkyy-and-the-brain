# Project Declaration
project(pbp)
cmake_minimum_required(VERSION 2.6)


# Platform dependent stuff.
if (APPLE)
	add_subdirectory(macosx)
endif (APPLE)

# Gather all the CPP source files.
file(GLOB_RECURSE sources RELATIVE ${CMAKE_SOURCE_DIR} *.cpp)


# Declare the executable.
if (APPLE)
	add_executable(pbp MACOSX_BUNDLE ${sources})
	target_link_libraries(pbp SDLMain)
	include_directories(SDLMain)
else (APPLE)
	add_executable(pbp ${sources})
endif (APPLE)


# Find the libraries required for the project.
find_package(SDL REQUIRED)
if (SDL_FOUND)
	include_directories(${SDL_INCLUDE_DIR})
	target_link_libraries(pbp ${SDL_LIBRARY})
else (SDL_FOUND)
	message(FATAL_ERROR "Error: SDL library not found")
endif (SDL_FOUND)
