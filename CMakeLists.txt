cmake_minimum_required(VERSION 2.8)
project(SDL2_Game)

# use FindSDL2.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../game)

# enable C++11
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -ggdb ${CMAKE_CXX_FLAGS}")

find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
	"src/"
	${SDL2_INCLUDE_DIR}
	${SDL2_GFX_INCLUDE_DIR}
	${SDL2_IMAGE_INCLUDE_DIR}
)

set(SOURCE_FILES
	"src/main.cpp"
	"src/coldet.cpp"
	"src/game.cpp"
	"src/layer.cpp"
	"src/particle.cpp"
	"src/texture.cpp"
	"src/vector.cpp"
)

add_executable(SDL2_Game ${SOURCE_FILES})

target_link_libraries(SDL2_Game
	${SDL2_LIBRARY}
	${SDL2_TTF_LIBRARY}
	${SDL2_IMAGE_LIBRARY}
)
