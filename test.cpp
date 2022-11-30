#include "aoc2022.h"

using namespace std;

void day_test(span<string> args)
{
	ostringstream ss;
	copy(args.begin(), args.end(), ostream_iterator<string>(ss, " "));
	cout << "invalid day with arguments: " << (args.empty() ? "no arguments" : ss.str());
}
