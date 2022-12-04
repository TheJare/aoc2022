#include "aoc2022.h"

using namespace std;

extern void day_test(span<string> args);
extern void day1(span<string> args);
extern void day2(span<string> args);
extern void day3(span<string> args);
extern void day4(span<string> args);

static function<void(span<string>)> days[] = {
    day_test,
    day1,
    day2,
    day3,
    day4,
    day_test,
};

int main(int argc, const char *argv[])
{
    vector<string> arguments(argv + min(2, argc), argv + argc);
    int day = clamp((argc > 1) ? atoi(argv[1]) : 0, (int)size(days) - 2, (int)size(days) - 1);

    days[day](arguments);
}
