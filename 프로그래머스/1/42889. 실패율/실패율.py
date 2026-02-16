from collections import defaultdict

def solution(N, stages):
    answer = []
    
    # 1) 스테이지별 인원 카운트
    cnt = defaultdict(int)
    for s in stages:
        cnt[s] += 1
    
    # 2) 실패율 계산
    remain = len(stages)   # 현재 도달 인원
    fail = []              # (스테이지, 실패율)
    
    for stage in range(1, N+1):
        if remain == 0:
            fail.append((stage, 0))
        else:
            rate = cnt[stage] / remain
            fail.append((stage, rate))
            remain -= cnt[stage]   # 다음 스테이지로 넘어감
    
    # 3) 실패율 내림차순 정렬
    fail.sort(key=lambda x: (-x[1], x[0])) #첫번째 기준, 같으면 두번째 기준 

    # x[1] 실패율 → 내림차순 → -붙임
    # x[0] 스테이지 → 오름차순
    
    # 4) 스테이지만 추출
    for stage, _ in fail: #fail안에는 튜플이 있음, stage = 스테이지, _ = 실패율
        answer.append(stage)
    
    return answer