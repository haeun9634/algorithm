import sys
import math

input = sys.stdin.readline

# 입력 받기
n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]

# 세그먼트 트리 초기화
tree_depth = math.ceil(math.log2(n))
tree_size = 1 << (tree_depth + 1)
segment_tree = [0] * tree_size

# 세그먼트 트리 생성
def make_segment_tree(node, start, end):
    if start == end:
        segment_tree[node] = arr[start]
        return segment_tree[node]
    mid = (start + end) // 2
    left_sum = make_segment_tree(node * 2, start, mid)
    right_sum = make_segment_tree(node * 2 + 1, mid + 1, end)
    segment_tree[node] = left_sum + right_sum
    return segment_tree[node]

# 값 갱신
def update_segment_tree(node, start, end, idx, diff):
    if idx < start or idx > end:
        return
    segment_tree[node] += diff
    if start != end:
        mid = (start + end) // 2
        update_segment_tree(node * 2, start, mid, idx, diff)
        update_segment_tree(node * 2 + 1, mid + 1, end, idx, diff)

# 구간 합 계산
def sum_segment_tree(node, start, end, left, right):
    if right < start or left > end:
        return 0
    if left <= start and end <= right:
        return segment_tree[node]
    mid = (start + end) // 2
    return sum_segment_tree(node * 2, start, mid, left, right) + sum_segment_tree(node * 2 + 1, mid + 1, end, left, right)

# 트리 만들기
make_segment_tree(1, 0, n - 1)

# 명령 처리
for _ in range(m + k):
    order, left, right = map(int, input().split())
    if order == 1:
        # 값 변경
        idx = left - 1
        diff = right - arr[idx]
        arr[idx] = right
        update_segment_tree(1, 0, n - 1, idx, diff)
    else:
        # 구간 합 출력
        print(sum_segment_tree(1, 0, n - 1, left - 1, right - 1))
