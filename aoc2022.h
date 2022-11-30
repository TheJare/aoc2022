
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

// aliases & stuff

namespace rs = std::ranges;
namespace rv = std::ranges::views;

// My stuff

extern void day_test(std::span<std::string> args);
extern void day1(std::span<std::string> args);
