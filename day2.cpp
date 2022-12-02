#include "aoc2022.h"

using namespace std;

static void day2_1(span<string> args)
{
    auto fn = args.empty() ? "data/day2.txt" : args[0].c_str();
    ifstream f(fn);
    int acc = 0;
    while (f)
    {
        string computer, me;
        f >> computer >> me;
        if (computer.empty())
            break;
        int cval = computer[0] - 'A';
        int mval = me[0] - 'X';
        int rval = (mval - cval + 4) % 3;
        int score = rval * 3 + mval + 1;
        acc += score;
    }
    cout << "round 1 score is " << acc << endl;
}

static void day2_2(span<string> args)
{
    auto fn = args.empty() ? "data/day2.txt" : args[0].c_str();
    ifstream f(fn);
    int acc = 0;
    while (f)
    {
        string computer, result;
        f >> computer >> result;
        if (computer.empty())
            break;
        int cval = computer[0] - 'A';
        int rval = result[0] - 'X';
        int mval = (cval + rval + 2) % 3;
        int score = rval * 3 + mval + 1;
        acc += score;
    }
    cout << "round 2 score is " << acc << endl;
}

extern void day2(span<string> args)
{
    day2_1(args);
    day2_2(args);
}
