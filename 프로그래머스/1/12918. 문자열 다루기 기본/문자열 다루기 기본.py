def solution(s):
    answer = True
    if len(s) == 4 or len(s) == 6:
        for i in range(len(s)):
            if '0' <= s[i] <='9':
                continue
            else:
                answer=False
                break
    else:
        answer=False
        
    return answer