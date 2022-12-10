#include "aoc2022.h"

using namespace std;

extern void day_test(span<string> args);
extern void day1(span<string> args);
extern void day2(span<string> args);
extern void day3(span<string> args);
extern void day4(span<string> args);
extern void day5(span<string> args);
extern void day6(span<string> args);
extern void day7(span<string> args);
extern void day8(span<string> args);
extern void day9(span<string> args);
extern void day10(span<string> args);

static function<void(span<string>)> days[] = {
    day_test,
    day1,
    day2,
    day3,
    day4,
    day5,
    day6,
    day7,
    day8,
    day9,
    day10,
    day_test,
};

int main(int argc, const char *argv[])
{
    vector<string> arguments(argv + min(2, argc), argv + argc);
    int day = clamp((argc > 1) ? atoi(argv[1]) : 0, (int)size(days) - 2, (int)size(days) - 1);

    days[day](arguments);
}
