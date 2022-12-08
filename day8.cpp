#include "aoc2022.h"

using namespace std;

extern void day8(span<string> args)
{
    auto fn = args.empty() ? "data/day8.txt" : args[0].c_str();
    ifstream f(fn);

    vector<string> map;
    for (string line; getline(f, line) && !line.empty();)
    {
        map.push_back(line);
    }
    int w = (int)map[0].length();
    int h = (int)map.size();
    static int directions[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int acc = w * 2 + h * 2 - 4;
    int max_score = 0;

    for (int y = 1; y < h - 1; ++y)
    {
        for (int x = 1; x < w - 1; ++x)
        {
            int tree_height = map[y][x];
            bool visible = false;
            int this_score = 1;
            for (auto &dir : directions)
            {
                int dir_score = 0;
                int cx = x, cy = y;
                bool dir_blocked = false;
                do // OMG a do..while in the wild!
                {
                    ++dir_score;
                    cx += dir[0];
                    cy += dir[1];
                    dir_blocked = map[cy][cx] >= tree_height;
                } while (!dir_blocked && cx > 0 && cx < w - 1 && cy > 0 && cy < h - 1);
                this_score *= dir_score;
                visible = visible || !dir_blocked;
            }
            acc += (int)visible;
            max_score = max(max_score, this_score);
        }
    }
    cout << "round 1 result is " << acc << endl;
    cout << "round 2 result is " << max_score << endl;
}
