def solution(lottos, win_nums):
    answer = []
    i=0
    score = [6,6,5,4,3,2,1]
    count = 0
    temp = 0

    max1 = 0

    for lo in range(6):    
        if (lottos[lo] == 0):
            max1 += 1
        for wn in range(6):
            if (lottos[lo] == win_nums[wn]):
                temp = 0
                temp+=1
                count+= 1
                if temp > 0:
                    break


    answer.append(score[count+max1])
    answer.append(score[count])


    return answer