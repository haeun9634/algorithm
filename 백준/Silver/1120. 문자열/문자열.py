def findDis(a,b):
    d=0
    for i in range(len(a)):
        if a[i]!=b[i]: d+=1
    return d
a, b = input().split()

if len(a) == len(b):
    d = findDis(a,b)
    print(d)
else:
    # koder와 topcoder
    # 하나씩 비교해감 같을수록 콤보?
    # b에 a가 있는지를 확인해야함
    # b에 a가 있는지 그리고 그대로 있는지를 봐야할듯
    # 슬라이딩 윈도우 << b의 부분 문자열에서 a랑 글자별 비교
    d=1e9
    for i in range(len(b)-len(a)+1):
        str = b[i : i+len(a)]
        d = min(findDis(a,str),d)
    print(d)