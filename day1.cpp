#include "aoc2022.h"

using namespace std;

extern void day1(span<string> args)
{
    auto fn = args.empty() ? "data/day1.txt" : args[0].c_str();
    ifstream f(fn);
    string line;
    int maxv[] = {0, 0, 0, 0};
    int acc = 0;
    while (getline(f, line))
    {
        if (is_emptyorws(line))
        {
            maxv[0] = acc;
            acc = 0;
            rs::sort(maxv);
        }
        else
        {
            acc += atoi(line.c_str());
        }
    }
    cout << "max calories is " << maxv[3] << endl;
    cout << "max 3 calories is " << reduce(maxv + 1, maxv + 4) << endl;
}
