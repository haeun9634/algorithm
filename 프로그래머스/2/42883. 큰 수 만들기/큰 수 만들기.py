#뒤에 큰 숫자 나오면 앞 숫자는 버려라
def solution(number, k):
    stack = []
    
    for num in number:
        # 나보다 작은 앞 숫자 제거
        while stack and k > 0 and stack[-1] < num: #스택의 마지막 숫자가 지금 숫자보다 작은지
            stack.pop()
            k -= 1
        
        stack.append(num)

    # 아직 덜 지웠으면 뒤에서 제거
    if k > 0:
        stack = stack[:-k]

    return ''.join(stack)