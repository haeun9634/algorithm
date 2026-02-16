graph = [[0] * 3 for _ in range(4)]
def makeGraph():
    global graph
    num=1
    for i in range(4):
        for j in range(3):
            graph[i][j]=num
            num+=1
    graph[3][0]='*'
    graph[3][1]=0
    graph[3][2]='#'
    

def findNow(num, key):
    x,y,a,b=0,0,0,0
    d=0
    for i in range(4):
        for j in range(3):
            if graph[i][j] == num:
                x,y=i,j
            if graph[i][j] == key:
                a,b=i,j
    
    print(f"x {x} y {y}")
    print(a,b)
    
    #거리 구하는 공식
    if x>a: d += x-a
    else: d+= a-x
    if y>b: d+= y-b
    else: d+= b-y
    
    return d
    
def solution(numbers, hand):
    answer = ''
    dx = [0, 0, -1, 1] #상화좌우
    dy = [-1, 1, 0, 0]
    nowleft = '*'
    nowright = '#'
    # 00 01 02 
    # 10 11 12
    # 20 21 22
    # 30 31 32
    
    makeGraph()
    
    for i in range(len(numbers)):
        if numbers[i] in [1,4,7]:
            answer+='L' #왼손 사용
            nowleft=numbers[i]
        elif numbers[i] in [3,6,9]:
            answer+='R'
            nowright=numbers[i]
        else:
            #거리 계산 로직
            leftdis= findNow(nowleft, numbers[i])
            rightdis= findNow(nowright, numbers[i])
            #print(f"nowleft {nowleft} nowright {nowright} numbers {numbers[i]}")
            #print(f"leftdis {leftdis} rightdis {rightdis}")
            if leftdis == rightdis:
                if hand == "left":
                    answer+='L' #왼손 사용
                    nowleft=numbers[i]
                else:
                    answer+='R'
                    nowright=numbers[i]
            elif leftdis < rightdis:
                answer+='L'
                nowleft=numbers[i]
            else:
                answer+='R'
                nowright=numbers[i]
       
    
    return answer