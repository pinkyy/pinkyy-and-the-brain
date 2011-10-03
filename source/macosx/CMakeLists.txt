# This file build a library from the SDLMain.m file against which we may link
# on Mac OS X systems in order to build the game.

if (APPLE)
	find_package(SDL REQUIRED)
	set(CMAKE_OSX_ARCHITECTURES "x86_64;i386")
	include_directories(${SDL_INCLUDE_DIR})
	add_library(SDLMain STATIC SDLMain.m)
endif (APPLE)
