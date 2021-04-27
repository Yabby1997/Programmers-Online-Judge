def solution(p):
    answer = solveRecursively(p)
    return answer


def solveRecursively(p):
    u = ''
    v = ''
    
    if len(p) == 0 :
        return ""
    
    for index in range(len(p)):
        temp = p[0:index + 1]
        if temp.count('(') == temp.count(')'):
            u = temp
            v = p[index+1:]
            break
            
    stack = []
    isCorrect = True
    for each in u:
        if each == '(':
            stack.append('(')
        elif each == ')':
            if len(stack) == 0:
                isCorrect = False
                break
            else:
                stack.pop()
    
    if isCorrect:
        return u + solveRecursively(v)
    
    trimmedU = u[1:-1]
    modifiedU = ''
    for each in trimmedU:
        if each == ')':
            modifiedU += '('
        elif each == '(':
            modifiedU += ')'
            
    return '(' + solveRecursively(v) + ')' + modifiedU
