#include "aoc2022.h"

using namespace std;

static size_t recur1(ifstream &f, size_t &total, vector<size_t> &sizes)
{
    size_t acc = 0;
    for (string line; getline(f, line) && line != "$ cd ..";)
    {
        if (isdigit(line[0]))
        {
            acc += atoi(line.c_str());
        }
        else if (line.starts_with("$ cd "))
        {
            size_t subf = recur1(f, total, sizes);
            acc += subf;
        }
    }
    if (acc < 100000)
    {
        total += acc;
    }
    sizes.push_back(acc);
    return acc;
}

extern void day7(span<string> args)
{
    auto fn = args.empty() ? "data/day7.txt" : args[0].c_str();
    ifstream f(fn);

    size_t total = 0;
    vector<size_t> sizes;
    size_t accum = recur1(f, total, sizes);
    size_t smallest_to_delete = 0;
    if (accum > 40000000)
    {
        size_t must_free = accum - 40000000;
        rs::sort(sizes);
        smallest_to_delete = *rs::lower_bound(sizes, must_free);
    }

    cout << "round 1 result is " << total << endl;
    cout << "round 2 result is " << smallest_to_delete << endl;
}
