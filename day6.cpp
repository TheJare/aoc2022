#include "aoc2022.h"

using namespace std;

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day6.txt" : args[0].c_str();
    ifstream f(fn);
    std::string line(std::istreambuf_iterator<char>{f}, {});

    int size = (part == 1) ? 4 : 14;

    int i;
    bool found = false;
    for (i = size; !found && i < line.length(); ++i)
    {
        found = true;
        for (int j = 0; found && j < size - 1; j++)
            for (int k = j + 1; found && k < size; k++)
                found = line[i - j] != line[i - k];
    }
    cout << "round " << part << " result is " << i << endl;
}

extern void day6(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
