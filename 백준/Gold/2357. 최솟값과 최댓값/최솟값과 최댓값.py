import sys
import math

input = sys.stdin.read
data = input().split()

N = int(data[0])
M = int(data[1])
arr = list(map(int, data[2:2 + N]))

h = math.ceil(math.log2(N))
size = 1 << (h + 1)
min_tree = [0] * size
max_tree = [0] * size

def init(node, start, end):
    if start == end:
        min_tree[node] = max_tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        init(node * 2, start, mid)
        init(node * 2 + 1, mid + 1, end)
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1])
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1])

def find_min_max(node, start, end, left, right):
    if right < start or end < left:
        return (float('inf'), -float('inf'))
    if left <= start and end <= right:
        return (min_tree[node], max_tree[node])
    mid = (start + end) // 2
    l = find_min_max(node * 2, start, mid, left, right)
    r = find_min_max(node * 2 + 1, mid + 1, end, left, right)
    return (min(l[0], r[0]), max(l[1], r[1]))

init(1, 0, N - 1)

output = []
idx = 2 + N
for _ in range(M):
    left = int(data[idx]) - 1  # 0-based indexing
    right = int(data[idx + 1]) - 1
    idx += 2
    res = find_min_max(1, 0, N - 1, left, right)
    output.append(f"{res[0]} {res[1]}")

print('\n'.join(output))
