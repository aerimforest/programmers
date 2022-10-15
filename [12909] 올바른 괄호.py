def solution(s):
    stack = []
    for braceket in s:
        if braceket == '(':
            stack.append(braceket)
        else:
            if stack == []:
                return False
            else:
                stack.pop()
    return stack == []