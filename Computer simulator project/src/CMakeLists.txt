cmake_minimum_required(VERSION 3.22)

set (MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(Practical2 main.cpp kbd.cpp ${MY_INCLUDE_DIR}/kbd.h ram.cpp ${MY_INCLUDE_DIR}/ram.h gpu.cpp ${MY_INCLUDE_DIR}/gpu.h disk.cpp ${MY_INCLUDE_DIR}/disk.h cpu.cpp ${MY_INCLUDE_DIR}/cpu.h)
target_include_directories(Practical2 PUBLIC ${MY_INCLUDE_DIR})