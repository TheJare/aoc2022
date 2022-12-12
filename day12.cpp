#include "aoc2022.h"

using namespace std;

struct Pos
{
    int x = 0, y = 0;

    bool operator==(const Pos &rhs) const { return (x == rhs.x && y == rhs.y); }
    int mdist(const Pos &rhs) const { return abs(rhs.x - x) + abs(rhs.y - y); }
    bool valid(int w, int h) const { return x >= 0 && x < w && y >= 0 && y < h; }
};

struct Node
{
    Pos pos;
    int dist;
    int heuristic;
};

static void part(span<string> args, int part)
{
    auto fn = args.empty() ? "data/day12.txt" : args[0].c_str();
    ifstream f(fn);

    Pos start, end;
    vector<string> map;
    for (string line; getline(f, line) && !line.empty();)
    {
        auto sx = line.find('S');
        if (sx != string::npos)
        {
            start = Pos{(int)sx, (int)map.size()};
            line[sx] = 'a';
        }
        auto ex = line.find('E');
        if (ex != string::npos)
        {
            end = Pos{(int)ex, (int)map.size()};
            line[ex] = 'z';
        }
        map.push_back(line);
    }
    int w = (int)map[0].length();
    int h = (int)map.size();
    static Pos directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> visited(h, vector<int>(w, w * h));

    auto cmp = [](const Node &lhs, const Node &rhs)
    {
        return lhs.heuristic > rhs.heuristic;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> open_list;
    open_list.push(Node{start, 0, start.mdist(end)});
    while (!open_list.empty())
    {
        Node cur = open_list.top();
        open_list.pop();
        if (cur.pos == end)
        {
            cout << format("round {} result is {}\n", part, cur.dist);
            break;
        }
        char curc = map[cur.pos.y][cur.pos.x];
        for (auto &dir : directions)
        {
            Pos next{cur.pos.x + dir.x, cur.pos.y + dir.y};
            if (next.valid(w, h) && (map[next.y][next.x] <= curc + 1))
            {
                int md = next.mdist(end);
                int dist = ((part == 2 && curc == 'a') ? 0 : cur.dist) + 1;
                int h = dist + md;
                if (visited[next.y][next.x] > h)
                {
                    visited[next.y][next.x] = h;
                    open_list.push(Node{next, dist, h});
                }
            }
        }
    }
}

extern void day12(span<string> args)
{
    part(args, 1);
    part(args, 2);
}
