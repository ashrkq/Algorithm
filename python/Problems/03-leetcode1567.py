class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        ans, pre, end, maxx, k = 0, 0, 0, 0, 1
        for a in nums:
            if a == 0:
                if k:
                    maxx = max(maxx, ans)
                else:
                    maxx = max(maxx, ans - pre, end)
                ans, pre, end,  k = 0, 0, 0, 1
                continue
            if a < 0:
                k ^= 1
                if not pre:
                    pre = ans + 1
                end = ans
            ans += 1
        if k:
            maxx = max(maxx, ans)
        else:
            maxx = max(maxx, ans - pre, end)
        return maxx