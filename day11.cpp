#include "aoc2022.h"

using namespace std;

struct Monkey
{
    deque<size_t> items;
    bool op_is_add;
    int operand; // always positive; -1 means "old" AKA current value
    int divider;
    int targets[2];
};

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day11.txt" : args[0].c_str();
    ifstream f(fn);

    vector<Monkey> monkeys;
    size_t totaldivisor = 1;
    for (;;)
    {
        Monkey m;
        string line;
        string dummy;

        // Monkey header
        if (!getline(f, line))
            break;

        // Starting items
        getline(f, line);
        auto sep = line.find(':');
        istringstream ilitems(line.substr(sep));
        for (int item; (ilitems >> dummy >> item) && !dummy.empty();)
            m.items.push_back(item);

        // Operation
        getline(f, line);
        sep = line.find('+');
        m.op_is_add = (sep != string::npos);
        if (!m.op_is_add)
            sep = line.find('*');
        istringstream ilop(line.substr(sep + 1));
        ilop >> dummy;
        m.operand = (dummy == "old") ? -1 : atoi(dummy.c_str());

        // Test
        getline(f, line);
        sep = line.find("by");
        istringstream iltest(line.substr(sep + 2));
        iltest >> m.divider;
        totaldivisor *= m.divider;

        // Throws
        for (auto n = 0; n < 2; ++n)
        {
            getline(f, line);
            auto sep = line.find("monkey");
            istringstream iltarget(line.substr(sep + 6));
            iltarget >> m.targets[n];
        }

        monkeys.push_back(m);
        if (!getline(f, line)) // empty line
            break;
    }

    vector<size_t> inspections(monkeys.size());

    int num_rounds = (part == 1) ? 20 : 10000;
    size_t reducer = (part == 1) ? 3 : 1;
    for (auto round = 0; round < num_rounds; ++round)
    {
        for (auto i = 0; i < monkeys.size(); ++i)
        {
            Monkey &m = monkeys[i];
            inspections[i] += m.items.size(); // Monkeys never throw to themselves
            while (!m.items.empty())
            {
                size_t item = m.items.front();
                m.items.pop_front();
                size_t operand = (m.operand < 0) ? item : m.operand;
                item = m.op_is_add ? (item + (size_t)operand) : (item * (size_t)operand);
                item = (item / reducer) % totaldivisor;
                int target = (item % m.divider) != 0;
                monkeys[m.targets[target]].items.push_back(item);
            }
        }
    }
    rs::sort(inspections);
    cout << format("part {} result is {}\n", part, inspections.end()[-1] * inspections.end()[-2]);
}

extern void day11(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
