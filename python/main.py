class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        ans = 0
        stoneValue.sort()
        while len(stoneValue) > 1:
            for i,value in enumerate(stoneValue):
                sum1 = stoneValue[:i+1]
                sum2 = stoneValue[i+1:]
                if sum1 >= sum2:
                    sum1 -= value
                    sum2 += value
                    ans += sum1
                    stoneValue = stoneValue[:i]
                    break
        return ans



