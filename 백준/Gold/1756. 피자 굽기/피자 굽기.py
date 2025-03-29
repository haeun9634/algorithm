# 피자 반죽 넣기 - 오븐 문제 (바로 실행 가능 버전)

d, n = map(int, input().split())
o = list(map(int, input().split()))
p = list(map(int, input().split()))

# 오븐 위에서부터 아래로 비내림차순으로 만들어야 함
for i in range(1, d):
    o[i] = min(o[i], o[i - 1])

cnt = 0  # 반죽 인덱스

for j in range(d - 1, -1, -1):
    if p[cnt] <= o[j]:
        p[cnt] = j + 1  # 넣은 위치 저장
        cnt += 1
    if cnt == n:
        break

if cnt == n:
    print(min(p[:n]))
else:
    print(0)
