cmake_minimum_required(VERSION 3.0)
project(Progetto_Tetris)

set(CMAKE_CXX_STANDARD 17)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(Tetris main.cpp Window.cpp Title.cpp Giuoco.cpp Griglia.cpp Tetramino.cpp Quadrato.cpp Linea.cpp classifica.cpp)
target_link_libraries( Tetris ${CURSES_LIBRARIES} )