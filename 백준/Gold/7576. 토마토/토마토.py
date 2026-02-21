from collections import deque

m,n = map(int,input().split())
graph=[]
dx = [0,0,-1,1]
dy = [-1,1,0,0]
tomatos=[]

def bfs():
    q = deque()
    for i in range(len(tomatos)):
        q.append((tomatos[i][0], tomatos[i][1])) #0일차 day

    while q:
        x,y= q.popleft()
        for dir in range(4):
            nx,ny = x+dx[dir], y+dy[dir]
            if 0<=nx<n and 0<=ny<m:
                if graph[nx][ny] ==0:
                    graph[nx][ny]=graph[x][y]+1
                    q.append((nx,ny))


def findTomato():
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                return False
    return True

def findMax():
    result = -1
    for i in range(n):
        for j in range(m):
            result = max(result,graph[i][j])

    if result==-1: return 0
    else: return result-1

for _ in range(n):
    row = list(map(int,input().split()))
    graph.append(row)

for i in range(n):
    for j in range(m):
        if graph[i][j]==1: #익은 토마토일 경우
            tomatos.append((i,j))

bfs()
if findTomato():
    print(findMax())
else:
    print("-1")