// aoc2022.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <functional>
#include <cstddef>
#include <format>

// TODO: Reference additional headers your program requires here.

using namespace std; // yeah

namespace rs = std::ranges;
namespace rv = std::ranges::views;

extern void day_test(span<string> args);
extern void day1(span<string> args);
