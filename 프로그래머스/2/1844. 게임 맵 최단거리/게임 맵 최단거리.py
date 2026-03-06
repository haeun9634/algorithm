from collections import deque 

dx = [0,0,-1,1]
dy = [-1,1,0,0]

def bfs(maps):
    q = deque()
    n,m = len(maps[0]), len(maps)
    visited = [[False] *n  for _ in range(m)]
    q.append((0,0,1))
    visited[0][0]=True
    while q:
        x,y,d = q.popleft()
        if x == m-1 and y==n-1: return d 
        for dir in range(4):
            nx, ny = x+dx[dir], y+dy[dir]
            if 0<=nx < m and 0<=ny< n:
                if maps[nx][ny] !=0 and not visited[nx][ny]:
                    maps[nx][ny] = maps[x][y] + 1
                    q.append((nx,ny,d+1))
                    visited[nx][ny]=True
    return -1               

def solution(maps):
    
    return bfs(maps)