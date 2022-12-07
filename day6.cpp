#include "aoc2022.h"

using namespace std;

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day6.txt" : args[0].c_str();
    ifstream f(fn);
    string line(istreambuf_iterator<char>{f}, {});

    int size = (part == 1) ? 4 : 14;

    auto check_unique = [&line, size](int &i)
    {
        for (int j = 0; j < size - 1; j++)
            for (int k = j + 1; k < size; k++)
                if (line[i - j] == line[i - k])
                {
                    i += size - k;
                    return false;
                }
        i++;
        return true;
    };

    int i = size;
    while (i < line.length() && !check_unique(i))
        ;
    cout << "round " << part << " result is " << i << endl;
}

extern void day6(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
