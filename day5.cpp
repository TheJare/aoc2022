#include "aoc2022.h"

using namespace std;

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day5.txt" : args[0].c_str();
    ifstream f(fn);
    vector<string> stacks;

    bool parsing_crates = true;

    for (string line; getline(f, line);)
    {
        if (is_emptyorws(line))
        {
            parsing_crates = false;
        }
        else if (parsing_crates)
        {
            for (size_t i = 1, j = 0; i < line.length(); i += 4, ++j)
            {
                if (stacks.size() <= j)
                {
                    stacks.push_back(string());
                }
                if (isalpha(line[i]))
                {
                    auto &stack = stacks[j];
                    stack.push_back(line[i]);
                }
            }
        }
        else
        {
            size_t num, from, to;
            string dummy;
            istringstream il(line);
            il >> dummy >> num >> dummy >> from >> dummy >> to;
            string group = stacks[from - 1].substr(0, num);
            stacks[from - 1].erase(0, num);
            if (part == 1)
            {
                rs::reverse(group);
            }
            stacks[to - 1].insert(0, group);
        }
    }
    cout << "round " << part << " result is ";
    rs::for_each(stacks, [](auto &stack)
                 { cout << stack[0]; });
    cout << endl;
}

extern void day5(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
