# leetcode  LCP 20

# 使用了python 默认的 lru_cache 进行优化
# 会把递归中已经找到过的值进行存储到一个字典中 进行剪枝操作，进行了优化
# 一个位置要们是之后退回要么是从前面走过来，在1这个位置的时候不可能是从后面退回来的所以特殊考虑
from functools import lru_cache


class Solution:
    def busRapidTransit(self, target: int, inc: int, dec: int, jump: List[int], cost: List[int]) -> int:
        @lru_cache(None)
        def rest(num):
            if num == 0:
                return 0

            result = num * inc
            for i, a in enumerate(jump):
                pre, nt = num // a, num % a
                result = min(result, rest(pre) + inc*nt + cost[i])
                if num > 1 and nt:
                    result = min(result, rest(pre + 1) +
                                 cost[i] + dec * (a - nt))
            return result

        return rest(target)
