#include "aoc2022.h"

using namespace std;

struct Pos
{
    int32_t x = 0, y = 0;

    uint64_t operator()(const Pos &c) const { return (uint64_t(c.y) << 32) + uint64_t(c.x); }
    bool operator==(const Pos &rhs) const { return (x == rhs.x && y == rhs.y); }
};

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day9.txt" : args[0].c_str();
    ifstream f(fn);

    unordered_set<Pos, Pos> trail;
    Pos rope[10];
    int rope_tail = (part - 1) * 8 + 1;
    trail.insert(rope[rope_tail]);
    for (;;)
    {
        string dir;
        int dist;
        f >> dir >> dist;
        if (dir.empty())
            break;
        while (dist-- > 0)
        {
            switch (dir[0])
            {
            case 'U': rope[0].y += 1; break;
            case 'D': rope[0].y -= 1; break;
            case 'L': rope[0].x -= 1; break;
            case 'R': rope[0].x += 1; break;
            }
            for (int knot = 0; knot < rope_tail; knot++)
            {
                Pos d{rope[knot].x - rope[knot + 1].x, rope[knot].y - rope[knot + 1].y};
                if (d.x * d.x + d.y * d.y > 2)
                {
                    if (d.x != 0) rope[knot + 1].x += d.x / abs(d.x);
                    if (d.y != 0) rope[knot + 1].y += d.y / abs(d.y);
                }
            }
            trail.insert(rope[rope_tail]);
        }
    }
    cout << "round " << part << " result is " << trail.size() << endl;
}

extern void day9(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
