def solution(new_id):
    # 1단계
    lowered_id = new_id.lower()
    
    # 2단계
    purified_id = '' 
    for each in lowered_id:
        if each.isalnum() or each == '-' or each == '_' or each == '.':
            purified_id += each
            
    # 3단계
    for i in reversed(range(2, len(purified_id))):
        purified_id = purified_id.replace('.' * i, '.')
        
    
    # 4단계
    if purified_id and purified_id[0] == '.' :
        purified_id = purified_id[1:]
    
    if purified_id and purified_id[-1] == '.':
       purified_id = purified_id[:-1]
        
    # 5단계
    if not purified_id:
        purified_id += 'a'
    
    # 6단계
    purified_id = purified_id[:15]
    if purified_id and purified_id[0] == '.' :
        purified_id = purified_id[1:]
    
    if purified_id and purified_id[-1] == '.':
       purified_id = purified_id[:-1]
    
    # 7단계
    while len(purified_id) < 3:
        purified_id += purified_id[-1]
        
    return purified_id
