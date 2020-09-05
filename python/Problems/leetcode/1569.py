from math import comb
# comb(n,m)
# 可以用来计算C(n,m)
# 递归求出每个子区间中的大于第一个数的数和小于第一个数的所有数
# 每个区间就是大于和下小于的相当于 n个球m个盒子  盒子不同可以空盒
# 计算就是C(n+m-1,n-1) 
class Solution:
    def sub_num(self,nums):
        n = len(nums)
        if n < 3:
            return 1
        num = nums[0]
        l1 = [i for i in nums if i > num]
        l2 = [i for i in nums if i < num]
        return ((self.dp[n-1][len(l1)] * self.sub_num(l1))%self.mod * self.sub_num(l2)) % self.mod
        
    
    def init_nums(self, dp, n):
        dp[0][0] = 1
        dp[1][0] = 1
        dp[1][1] = 1
        for i in range(2,n):
            for j in range(i+1):
                if j == 0: dp[i][j] = 1
                elif j == i: dp[i][j] = 1
                else: dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                dp[i][j] = dp[i][j] % self.mod
    def numOfWays(self, nums: List[int]) -> int:
        # 直接使用1e9+7是float 类型 会有浮点数的溢出
        self.mod = int(1e9+7)
        n = len(nums)
        self.dp = [ [0 for i in range(n+1) ] for i in range(n+1) ]
        self.init_nums(self.dp, n+1)
        return (self.sub_num(nums) - 1) % self.mod