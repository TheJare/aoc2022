#include "aoc2022.h"

using namespace std;

static function<void(span<string>)> days[] = {
    day_test,
    day1,
    day_test,
};

int main(int argc, const char *argv[])
{
    vector<string> arguments(argv + min(2, argc), argv + argc);
    int day = clamp((argc > 1) ? atoi(argv[1]) : 0, 0, (int)size(days) - 1);

    // cout << "day " << day << " with " << arguments.size() << " parameters" << endl;

    days[day](arguments);
}
