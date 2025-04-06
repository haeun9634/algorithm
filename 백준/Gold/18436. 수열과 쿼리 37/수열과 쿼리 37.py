import sys
input = sys.stdin.read
data = input().split()

# 입력 처리
idx = 0
N = int(data[idx]); idx += 1
A = list(map(int, data[idx:idx+N])); idx += N
M = int(data[idx]); idx += 1
queries = data[idx:]

# 세그먼트 트리 초기화
even_tree = [0] * (4 * N)

def build(node, start, end):
    if start == end:
        even_tree[node] = 1 if A[start] % 2 == 0 else 0
    else:
        mid = (start + end) // 2
        build(2*node, start, mid)
        build(2*node+1, mid+1, end)
        even_tree[node] = even_tree[2*node] + even_tree[2*node+1]

def update(node, start, end, idx, val):
    if start == end:
        A[idx] = val
        even_tree[node] = 1 if val % 2 == 0 else 0
    else:
        mid = (start + end) // 2
        if idx <= mid:
            update(2*node, start, mid, idx, val)
        else:
            update(2*node+1, mid+1, end, idx, val)
        even_tree[node] = even_tree[2*node] + even_tree[2*node+1]

def query_even(node, start, end, l, r):
    if r < start or end < l:
        return 0
    if l <= start and end <= r:
        return even_tree[node]
    mid = (start + end) // 2
    left = query_even(2*node, start, mid, l, r)
    right = query_even(2*node+1, mid+1, end, l, r)
    return left + right

build(1, 0, N-1)

# 쿼리 처리
output = []
q_idx = 0
for _ in range(M):
    t = int(queries[q_idx]); q_idx += 1
    if t == 1:
        i = int(queries[q_idx]) - 1; q_idx += 1
        x = int(queries[q_idx]); q_idx += 1
        update(1, 0, N-1, i, x)
    else:
        l = int(queries[q_idx]) - 1; q_idx += 1
        r = int(queries[q_idx]) - 1; q_idx += 1
        even_count = query_even(1, 0, N-1, l, r)
        if t == 2:
            output.append(str(even_count))
        else:
            output.append(str((r - l + 1) - even_count))

print('\n'.join(output))
