from collections import deque

visited = [False]*205
def bfs(n, graph):
    q = deque()
    q.append(n)
    visited[n]=True
    while q:
        now = q.popleft()
        for nxt in range(len(graph[0])):
            if now!=nxt and graph[now][nxt]==1 and not visited[nxt]: #연결되어있다면 
                q.append(nxt)
                visited[nxt]=True
            
    
    
def solution(n, computers):
    answer = 0
    graph = [[0]*n for _ in range(n)]
    temp = 2
    for i in range(n):
        if not visited[i]:
            bfs(i,computers)
            answer+=1
    
    return answer