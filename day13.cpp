#include "aoc2022.h"

using namespace std;

namespace
{

    struct Node
    {
        int value; // if -1, then the value here is in the nodes vector
        vector<Node> nodes;

        Node() = default;
        Node(int v) : value(v){};

        static int parse(string_view line, Node &node)
        {
            int i = 0;
            if (line[i] == '[')
            {
                ++i;
                node.value = -1;
                while (line[i] != ']')
                {
                    Node &n = node.nodes.emplace_back();
                    i += parse(line.substr(i), n);
                    i += (line[i] == ',');
                }
                ++i;
            }
            else
            {
                int v = 0;
                while (isdigit(line[i]))
                {
                    v = v * 10 + line[i++] - '0';
                }
                node.value = v;
            }
            return i;
        }

        static strong_ordering compare_lists(vector<Node> const &lhs, vector<Node> const &rhs)
        {
            for (int i = 0; i < lhs.size() && i < rhs.size(); ++i)
            {
                auto r = lhs[i] <=> rhs[i];
                if (r != strong_ordering::equal)
                    return r;
            }
            return lhs.size() <=> rhs.size();
        }

        strong_ordering operator<=>(Node const &rhs) const
        {
            if (value >= 0 && rhs.value >= 0)
            {
                return value <=> rhs.value;
            }
            auto lvalue = vector<Node>{Node{value}};
            auto rvalue = vector<Node>{Node{rhs.value}};
            return compare_lists((value < 0) ? nodes : lvalue, (rhs.value < 0) ? rhs.nodes : rvalue);
        }
    };

    static void part(span<string> args, int part)
    {
        auto fn = args.empty() ? "data/day13.txt" : args[0].c_str();
        ifstream f(fn);

        int i = 1, acc = 0;
        for (string left, right; getline(f, left) && getline(f, right); ++i)
        {
            Node nl, nr;
            Node::parse(left, nl);
            Node::parse(right, nr);
            acc += ((nl <=> nr) < 0) * i;
            getline(f, left);
        }
        cout << format("round {} result is {}\n", part, acc);
    }
}

extern void day13(span<string> args)
{
    part(args, 1);
    // part(args, 2);
}
