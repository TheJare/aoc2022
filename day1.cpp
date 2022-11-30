#include "aoc2022.h"

using namespace std;

void day1(span<string> args)
{
    auto fn = args.empty() ? "data/input.txt" : args[0].c_str();
    ifstream f(fn);
    size_t m = 0;
    while (f)
    {
        string k;
        f >> k;
        m = max(k.size(), m);
    }
    cout << "max token is " << m;
}
