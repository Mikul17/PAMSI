cmake_minimum_required(VERSION 3.25)
project(PAMSI)

set(CMAKE_CXX_STANDARD 17)

add_executable(PAMSI main.cpp Game.cpp Game.h Board.cpp Board.h Move.cpp Move.h ComputerPlayer.cpp ComputerPlayer.h)
