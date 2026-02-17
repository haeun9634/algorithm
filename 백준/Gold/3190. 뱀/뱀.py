from collections import deque

n = int(input())
k = int(input())

board = [[0]*n for _ in range(n)]

for _ in range(k):
    r,c = map(int,input().split())
    board[r-1][c-1]=1

l = int(input())
turns = deque()

for _ in range(l):
    x,c = input().split()
    turns.append((int(x), c))

# 방향: 북 동 남 서
dx = [-1,0,1,0]
dy = [0,1,0,-1]
d=1

snake = deque()
snake.append((0,0)) # 뱀 시작 위치
board[0][0]=2 # 뱀 존재

time = 0

while True:
    time += 1

    # 머리 이동
    head_x, head_y = snake[0]
    nx = head_x + dx[d]
    ny = head_y + dy[d]

    # 벽 or 자기 몸 충돌 체크
    if nx < 0 or ny < 0 or nx >= n or ny >= n:
        print(time)
        break
    if board[nx][ny] == 2:
        print(time)
        break

    # 이동 처리
    if board[nx][ny] == 1: #사과 있음 -> 몸 길이 증가
        board[nx][ny]=2
        snake.appendleft((nx,ny))
    else: # 사과 없음 -> 꼬리 제거
        board[nx][ny] = 2
        snake.appendleft((nx,ny))
        tail_x, tail_y = snake.pop()
        board[tail_x][tail_y]=0

    # 방향 회전은 무조건 이동 후에 회전
    if turns and time == turns[0][0]:
        _, c = turns.popleft()
        if c == 'L':
            d = (d - 1) % 4
        else:
            d = (d + 1) % 4