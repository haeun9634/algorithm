# 기본적으로 빗물이 고일 수 있는지 여부는 해당 칸의 양옆으로 더 높은 벽이 있어야 함
# 각 위치에서  가능한 높이를 기준으로 최대 높이를 구한 후 확인 
def trap(height):
    if not height:
        return 0
    
    n = len(height)
    
    # 왼쪽에서의 최대 높이를 저장할 리스트
    left_max = [0] * n
    left_max[0] = height[0]
    
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], height[i])
        # i번째까지의 왼쪽에서의 최대 높이 
    
    # 오른쪽에서의 최대 높이를 저장할 리스트
    right_max = [0] * n
    right_max[n-1] = height[n-1]
    
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], height[i])
    
    # 고일 수 있는 빗물의 양 계산
    total_water = 0
    for i in range(n):
        total_water += min(left_max[i], right_max[i]) - height[i]
    
    return total_water

# 입력
H, W = map(int, input().split())  # 세로 길이 H, 가로 길이 W
height = list(map(int, input().split()))  # 각 칸의 높이

print(trap(height))
