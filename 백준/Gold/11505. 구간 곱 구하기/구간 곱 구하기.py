import sys
import math
input = sys.stdin.read
MOD = 1_000_000_007

data = list(map(int, input().split()))
N, M, K = data[0], data[1], data[2]
arr = data[3:3+N]
queries = data[3+N:]

# 세그먼트 트리 생성
size = 2 ** (math.ceil(math.log2(N)) + 1)
tree = [1] * size

def build(node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        mid = (start + end) // 2
        build(node*2, start, mid)
        build(node*2+1, mid+1, end)
        tree[node] = (tree[node*2] * tree[node*2+1]) % MOD

def update(node, start, end, index, value):
    if start == end:
        tree[node] = value
    else:
        mid = (start + end) // 2
        if index <= mid:
            update(node*2, start, mid, index, value)
        else:
            update(node*2+1, mid+1, end, index, value)
        tree[node] = (tree[node*2] * tree[node*2+1]) % MOD

def query(node, start, end, left, right):
    if right < start or end < left:
        return 1
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    l = query(node*2, start, mid, left, right)
    r = query(node*2+1, mid+1, end, left, right)
    return (l * r) % MOD

# 초기 트리 구성
build(1, 0, N-1)

# 쿼리 처리
output = []
for i in range(0, len(queries), 3):
    a, b, c = queries[i], queries[i+1], queries[i+2]
    if a == 1:
        update(1, 0, N-1, b-1, c)
    else:
        result = query(1, 0, N-1, b-1, c-1)
        output.append(str(result))

print("\n".join(output))
