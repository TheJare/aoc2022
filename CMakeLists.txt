# CMakeList.txt : CMake project for aoc2022, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("aoc2022")

# Add source to this project's executable.
add_executable (aoc2022 "aoc2022.cpp" "aoc2022.h" "test.cpp" "day1.cpp" "day2.cpp" "day3.cpp" "day4.cpp" "day5.cpp" "day6.cpp" "day7.cpp" "day8.cpp" "day9.cpp" "day10.cpp" "day11.cpp" "day12.cpp" "day13.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET aoc2022 PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
