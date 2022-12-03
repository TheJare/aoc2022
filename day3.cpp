#include "aoc2022.h"

using namespace std;

static void part1(span<string> args)
{
    auto fn = args.empty() ? "data/day3.txt" : args[0].c_str();
    ifstream f(fn);
    string line;
    size_t acc = 0;
    while (getline(f, line))
    {
        size_t s = line.length() / 2;
        auto h1 = string_view(&line.at(0), s);
        auto h2 = string_view(&line.at(s), s);
        for (auto c : h1)
        {
            if (h2.contains(c))
            {
                acc += isupper(c) ? (c - 'A' + 27) : (c - 'a' + 1);
                break;
            }
        }
    }
    cout << "round 1 score is " << acc << endl;
}

static void part2(span<string> args)
{
    auto fn = args.empty() ? "data/day3.txt" : args[0].c_str();
    ifstream f(fn);
    string lines[3];
    size_t acc = 0;
    while (getline(f, lines[0]) && getline(f, lines[1]) && getline(f, lines[2]))
    {
        for (auto c : lines[0])
        {
            if (lines[1].contains(c) && lines[2].contains(c))
            {
                acc += isupper(c) ? (c - 'A' + 27) : (c - 'a' + 1);
                break;
            }
        }
    }
    cout << "round 2 score is " << acc << endl;
}

extern void day3(span<string> args)
{
    part1(args);
    part2(args);
}
