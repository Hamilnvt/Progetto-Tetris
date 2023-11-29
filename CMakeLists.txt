cmake_minimum_required(VERSION 3.0)
project(Progetto_Tetris)

set(CMAKE_CXX_STANDARD 17)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(main main.cpp Window.cpp Window.h)
target_link_libraries( main ${CURSES_LIBRARIES} )
