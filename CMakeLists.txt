cmake_minimum_required(VERSION 3.0)
project(PA01)
set(CMAKE_CXX_STANDARD 14)


set (input01 "input/input01.txt")
#set (input02 "input/input02.txt")
#set (input03 "input/input03.txt")
#set (input04 "input/input04.txt")
#set (input05 "input/input05.txt")
#set (input06 "input/input06.txt")
#set (input07 "input/input07.txt")
#set (input08 "input/input08.txt")
#set (input09 "input/input09.txt")
#set (input10 "input/input10.txt")
#set (input11 "input/input11.txt")
#set (input12 "input/input12.txt")
#set (input13 "input/input13.txt")
#set (input14 "input/input14.txt")
#set (input15 "input/input15.txt")

configure_file(input/input01.txt COPYONLY)

add_executable(PA01 src/main.cpp src/art.cpp src/art.h src/sorts.cpp src/sorts.h src/fileio.cpp src/fileio.h)

target_compile_features(PA01 PRIVATE cxx_std_20)