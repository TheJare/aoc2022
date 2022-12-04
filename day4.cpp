#include "aoc2022.h"

using namespace std;

static void part1(span<string> args)
{
    auto fn = args.empty() ? "data/day4.txt" : args[0].c_str();
    ifstream f(fn);
    size_t acc = 0;

    for (string line; getline(f, line);)
    {
        if (is_emptyorws(line))
            continue;

        // C style
        int a0, a1, b0, b1;
        sscanf(line.c_str(), "%d-%d,%d-%d", &a0, &a1, &b0, &b1);
        acc += (a0 >= b0 && a1 <= b1) || (b0 >= a0 && b1 <= a1);
    }
    cout << "round 1 score is " << acc << endl;
}

static void part2(span<string> args)
{
    auto fn = args.empty() ? "data/day4.txt" : args[0].c_str();
    ifstream f(fn);
    size_t acc = 0;

    for (string line; getline(f, line);)
    {
        if (is_emptyorws(line))
            continue;

        // C++ style
        size_t a0, a1, b0, b1;
        char c;
        istringstream il(line);
        il >> a0 >> c >> a1 >> c >> b0 >> c >> b1;
        acc += a0 <= b1 && a1 >= b0;
    }
    cout << "round 2 score is " << acc << endl;
}

extern void day4(span<string> args)
{
    part1(args);
    part2(args);
}
