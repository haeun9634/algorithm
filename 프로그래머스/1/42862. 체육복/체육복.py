def solution(n, lost, reserve):
    # 여벌 가져왔지만 도난당한 학생 먼저 처리
    # 이 학생들은 lost와 reserve 양쪽에서 제거
    real_lost = set(lost) - set(reserve)
    real_reserve = set(reserve) - set(lost)
    
    for r in sorted(real_reserve):
        if r - 1 in real_lost:
            real_lost.remove(r - 1)
        elif r + 1 in real_lost:
            real_lost.remove(r + 1)
    
    return n - len(real_lost)