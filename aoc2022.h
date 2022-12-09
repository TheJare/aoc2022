
#pragma once

#define _CRT_SECURE_NO_WARNINGS

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
#include <numeric>
#include <cctype>
#include <iterator>
#include <unordered_set>

// aliases & stuff

namespace rs = std::ranges;
namespace rv = std::ranges::views;

// My stuff

inline bool is_emptyorws(std::string const &str)
{
    return str.find_first_not_of(" \r\n\t\v\f") == std::string::npos;
}
