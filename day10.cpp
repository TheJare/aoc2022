#include "aoc2022.h"

using namespace std;

extern void day10(span<string> args)
{
    auto fn = args.empty() ? "data/day10.txt" : args[0].c_str();
    ifstream f(fn);

    size_t acc = 0;
    int signal = 1;
    ostringstream crt;
    auto process_pixel = [&crt, cur_cycle = size_t{}](int signal) mutable
    {
        int row = cur_cycle++ % 40;
        crt << ((row >= signal - 1 && row <= signal + 1) ? '#' : ' ');
        return (row == 19) ? cur_cycle * signal : 0;
    };
    for (string op; (f >> op) && !op.empty();)
    {
        acc += process_pixel(signal);
        if (op == "addx")
        {
            acc += process_pixel(signal);
            int val;
            f >> val;
            signal += val;
        }
    }
    cout << format("round 1 result is {}\nround 2 result is:\n", acc);
    rs::for_each(crt.view() | rv::chunk(40), [](auto scanline)
                 { cout << "  " << string_view(scanline.begin(), scanline.end()) << endl; });
}
