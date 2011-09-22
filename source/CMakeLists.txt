project(pbp)
cmake_minimum_required(VERSION 2.6)

find_package(SDL)

link_directories(
	${SDL_LIBRARY_DIRS}
)
include_directories(
	${SDL_INCLUDE_DIRS}
)

add_executable(
	pbp
	main.cpp
)

target_link_libraries(
	pbp
	${SDL_LIBRARY}
)

