import functools


def cmp(a, b):
    return int(a > b) - int(a < b)


def parse_line(line):
    points = line.split(" -> ")
    return [(int(p[0]), int(p[1])) for p in points.split(",")]


strokes = []
with open("data/input.txt") as f:
    lines = f.readlines()
    for line in lines:
        points = line.split(" -> ")
        print([p for point in points for p in point.split(",")])
        strokes.append(
            [(int(p[0]), int(p[1])) for point in points for p in point.split(",")]
        )

points = [s for s in strokes for (x, y) in s]
minx = min([x for (x, y) in points])
maxx = max([x for (x, y) in points])
maxy = min([y for (x, y) in points])
map = [[" "] * (maxx + 1 - minx) for i in range(maxy + 1)]


def printmap(map):
    for l in map:
        print("".join(map[l]))


for s in strokes:
    for i in range(len(s) - 1):
        [p0, p1] = s[i : i + 1]
        [dx, dy] = [abs(p1[0] - p0[0]), abs(p1[1] - p0[1])]
        [x, y] = [min(p1[0], p0[0]), min(p1[1], p0[1])]
        for i in range(max(dx, dy) + 1):
            map[y][x - minx] = "#"
            [x, y] = [x + dx, y + dy]
printmap(map)

# print(f"part 1 = {acc}")
