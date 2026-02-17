graph=[]
n,m = map(int,input().split())
r,c,d = map(int,input().split())

for _ in range(n):
    row = list(map(int,input().split()))
    graph.append(row)

dx = [-1, 0, 1, 0]  # 북 동 남 서
dy = [ 0, 1, 0,-1]
dir = [0,1,2,3] #북, 동, 남, 서
result = 0 # 청소한 갯수

# 00 01 02
# 10 11 12
# 20 21 22

while True:
    if graph[r][c] == 0:
        result+=1
        graph[r][c]=3 #청소 완료
    nextR=r
    nextC=c

    #print(f"r: {r} c: {c} d: {d}")
    moved = False
    for _ in range(4):
        d = (d + 3) % 4

        if d==0:
            nextR=r-1
            nextC=c
        elif d==1:
                nextR=r
                nextC=c+1
        elif d==2:
                nextR=r+1
                nextC=c
        elif d==3:
            nextR=r
            nextC=c-1

        if graph[nextR][nextC]==0:
            r=nextR
            c=nextC
            moved=True
            break
            #반시계 방향으로 90도 회전,
            #앞쪽이 청소되지 않은 빈 칸인 경우 전진, 아닌 경우 그냥 회전만 한상태로 다시 돌아감

    if moved:
        continue

    # 후진 로직
    if d == 0:
            nextR = r + 1
            nextC = c
    elif d == 1:  # 동
            nextR = r
            nextC = c - 1
    elif d == 2:  # 남
            nextR = r - 1
            nextC = c
    elif d == 3:
            nextR = r
            nextC = c + 1

    if graph[nextR][nextC] == 1:  # 후진 불가능
        print(result)
        break
    else:
        r = nextR
        c = nextC
