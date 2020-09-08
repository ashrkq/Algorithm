
# 优先处理出来数组中的前缀和后缀
# 如果长度等于总长度那么长度就是 0
# 其他的话就是从前缀的前面取 或者从后缀的后面取 总数就是总长度
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        x = -1
        l1 = []
        for a in arr:
            if a >= x: l1.append(a); x = a
            else: break
        l2 = []
        x = arr[-1]
        for a in arr[::-1]:
            if a <= x: l2.append(a); x = a
            else: break
        if len(l1) == n: return 0
        n1, n2 = len(l1), len(l2)
        ans = min(n - n1, n- n2)
        l2 = l2[::-1]
        i, j = 0 ,0
        while i < n1 and j < n2:
            if l1[i] <= l2[j]:
                ans = min(ans, n - i - (n2-j+1))
                i += 1
            else:
                j += 1
        return ans