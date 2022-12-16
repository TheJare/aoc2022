import functools


def cmp(a, b):
    return int(a > b) - int(a < b)


def compare_lists(l, r):
    if type(l) == int and type(r) == int:
        return cmp(l, r)
    if type(l) == int:
        l = [l]
    if type(r) == int:
        r = [r]
    for i in range(min(len(l), len(r))):
        c = compare_lists(l[i], r[i])
        if c != 0:
            return c
    return cmp(len(l), len(r))


with open("data/day13.txt") as f:
    lines = f.readlines()
acc = 0
packets = []
for i in range(0, len(lines), 3):
    l = eval(lines[i])
    r = eval(lines[i + 1])
    packets.extend([l, r])
    if compare_lists(l, r) < 0:
        acc += 1 + i // 3

print(f"part 1 = {acc}")

d1 = [[6]]
d2 = [[2]]
packets.extend([d1, d2])
sorted_packets = sorted(packets, key=functools.cmp_to_key(compare_lists))
print("part 2 =", (sorted_packets.index(d1) + 1) * (sorted_packets.index(d2) + 1))
