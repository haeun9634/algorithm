from collections import deque

n,m = map(int,input().split())
graph = []
b = [] #바이러스 리스트
q = deque()
dx = [0,0,-1,1]
dy = [-1,1,0,0]
result = 0

def bfs(graph): #시뮬레이션 그레프 받아옴
    for i in range(len(b)):
        q.append((b[i][0], b[i][1])) #바이러스 쿠에 넣기

    while q:
        x,y = q.popleft()
        for dir in range(4):
            nx,ny = x+dx[dir], y+dy[dir]
            if 0<=nx<n and 0<=ny<m:
                if graph[nx][ny]==0:
                    graph[nx][ny]=2
                    q.append((nx,ny))

def countZero(graph):
    cnt=0
    for i in range(n):
        for j in range(m):
            if graph[i][j]==0:
                cnt+=1
    return cnt

import copy

def start(graph):
    global result
    temp_graph = copy.deepcopy(graph)  # BFS에 원본 안 건드리게
    bfs(temp_graph)
    result = max(countZero(temp_graph), result)
    
def dfs(graph,count):
    if count == 3:
        start(graph)
        return

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                dfs(graph, count + 1)
                graph[i][j] = 0

for _ in range(n):
    row = list(map(int,input().split()))
    graph.append(row)

for i in range(n):
    for j in range(m):
        if graph[i][j]==2:
            b.append((i,j))

dfs(graph,0)
print(result)