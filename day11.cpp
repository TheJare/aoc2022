#include "aoc2022.h"

using namespace std;

namespace
{

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
        string input(istreambuf_iterator<char>{f}, {});
        vector<Monkey> monkeys;
        size_t totaldivisor = 1;

        auto parserstr = R"(Monkey \d+:\n)"
                         R"(  Starting items: ([\d\s,]*\d+)\n)"
                         R"(  Operation: new = old ([\*\+]) (\w+)\n)"
                         R"(  Test: divisible by (\d+)\n)"
                         R"(    If true: throw to monkey (\d+)\n)"
                         R"(    If false: throw to monkey (\d+))";
        auto parser = regex(parserstr);

        smatch match;
        for (auto input_start = input.cbegin();
             regex_search(input_start, input.cend(), match, parser);
             input_start = match.suffix().first)
        {
            Monkey m{
                .items{},
                .op_is_add{match[2] == "+"},
                .operand{(match[3] == "old") ? -1 : atoi(string(match[3]).c_str())},
                .divider{atoi(string(match[4]).c_str())},
            };
            rs::for_each(rv::split(match[1].str(), string_view(", ")), [&m](auto item)
                         { m.items.push_back(atoi(string(item.begin(), item.end()).c_str())); });
            m.targets[0] = atoi(string(match[5]).c_str());
            m.targets[1] = atoi(string(match[6]).c_str());

            totaldivisor *= m.divider;
            monkeys.push_back(m);
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
}

extern void day11(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
