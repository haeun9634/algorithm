from collections import deque, Counter

n = int(input())
graph=[]
visited = [[False]*n for _ in range(n)]

dx=[0,0,-1,1]
dy=[-1,1,0,0]

def bfs(x,y,cnt):
    q = deque()
    q.append((x,y))
    graph[x][y]=cnt
    size = 1
    while q:
        x,y = q.popleft()
        for dir in range(4):
            nx,ny = x+dx[dir], y+dy[dir]
            if 0<=nx<n and 0<=ny<n:
                if graph[nx][ny] == 1:
                    graph[nx][ny]=cnt
                    size += 1
                    q.append((nx,ny))
    
    return size

def findcnt(num):
    count=0
    for i in range(n):
        for j in range(n):
            if graph[i][j]==num:
                count+=1
    return count

for _ in range(n):
    row = list(map(int,input()))
    graph.append(row)

cnt=1
sizes=[]
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            cnt+=1
            size = bfs(i,j,cnt)
            sizes.append(size)

print(len(sizes))

for s in sorted(sizes):
    print(s)
