# [12924] 숫자의 표현
def solution(n):
    ans = 1
    for i in range(1, n+1):
        sum = i
        for j in range(i+1, n+1):
            if sum == n:
                ans += 1
                break
            elif sum < n:
                sum += j
            else:
                break
                
    return ans