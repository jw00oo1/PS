def solution(sticker):
    answer = 0
    n = len(sticker)
    dp_0 = [0] * (n+1)
    dp_1 = [0] * (n+1)
    dp_1[0] = sticker[0]

    for idx in range(1,n):
        dp_0[idx] = max(dp_0[idx-2 if idx-2 >= 0 else -1] + sticker[idx], dp_0[idx-1 if idx-1 >= 0 else -1])
        dp_1[idx] = max(dp_1[idx-2 if idx-2 >= 0 else -1] + sticker[idx], dp_1[idx-1 if idx-1 >= 0 else -1])
    
    if n == 1:
        answer = sticker[0]
    elif n == 2:
        answer = max(sticker[0], sticker[1])
    else:
        answer = max(dp_0[-2], dp_1[-3])
    
    return answer

print(solution([2,1,1,5,1]))