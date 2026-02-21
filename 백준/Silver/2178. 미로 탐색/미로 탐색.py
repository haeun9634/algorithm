from collections import deque
n,m = map(int, input().split())
graph=[]

dx = [0,0,-1,1]
dy = [-1,1,0,0]
visited = [[False]*m for _ in range(n)]

def bfs(x, y):
    q = deque()
    q.append((x, y, 1))
    visited[x][y] = True

    while q:
        x, y, d = q.popleft()

        if x == n - 1 and y == m - 1:
            return d

        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]

            if 0 <= nx < n and 0 <= ny < m:
                if not visited[nx][ny] and graph[nx][ny] == 1:
                    visited[nx][ny] = True
                    q.append((nx, ny, d + 1))



for _ in range(n):
    row = list(map(int, input()))
    graph.append(row)

print(bfs(0,0))

#원래 1,1이지만 우리는 0 0에서 시작.
