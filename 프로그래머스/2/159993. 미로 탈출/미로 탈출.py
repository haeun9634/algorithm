from collections import deque
dx = [0,0,-1,1]
dy = [-1,1,0,0]

def bfs(sx, sy, visited,maps, graph):
    n,m = len(maps), len(maps[0])
    q = deque()
    q.append((sx,sy,0))
    visited[sx][sy]=True
    graph[sx][sy]=0
    while q:
        x,y,d= q.popleft()
        for dir in range(4):
            nx,ny = x+dx[dir], y+dy[dir]
            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and maps[nx][ny] != 'X':
                    q.append((nx,ny,d+1))
                    graph[nx][ny]=d+1
                    visited[nx][ny]=True
    
    
def solution(maps):
    answer = 0
    n,m = len(maps), len(maps[0])
    visited=[[False]*m for _ in range(n)]
    sx,sy,lx,ly,ex,ey=0,0,0,0,0,0
    graph=[[0]*m for _ in range(n)]
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j]=='S':
                sx, sy = i,j
            elif maps[i][j]=='L':
                lx,ly = i,j
            elif maps[i][j]=='E':
                ex,ey = i,j 
                
    bfs(sx,sy,visited, maps, graph)
    
    if not visited[lx][ly]: return -1 #레버 못당기면 -1
    if visited[lx][ly]: #레버 당겼으면
        d = graph[lx][ly]#L까지의 거리, graph[lx][ly], 
            
        #초기화
        visited=[[False]*m for _ in range(n)]
        graph=[[0]*m for _ in range(n)]
            
        #lx,ly에서 다시 ex,ey까지 가는 거리 계산. 
        bfs(lx,ly,visited, maps, graph)
            
        if not visited[ex][ey]: return -1 
        else: return d+graph[ex][ey]
            
    
    
    return answer