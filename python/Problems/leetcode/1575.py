# 使用dp[i][k] 记录花费k的油到start达i的次数
# 先到达i然后再到达j的值
# 转移就是dp[j][k] = dp[j][k + abs(loacation[i] - location[j])] + dp[i][k]
# 结果就是dp[finish][0] - dp[finish][fuel] 的和
class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        n = len(locations)
        dp = [[0 for i in range(fuel + 1)] for i in range(n) ]
        dp[start][0] = 1
        for k in range(fuel + 1):
            for i in range(n):
                for j in range(n):
                    if i == j or k + abs(locations[i] - locations[j]) > fuel: continue
                    dp[j][k + abs(locations[i] - locations[j])] += dp[i][k]
        for i in range(fuel): dp[finish][fuel] += dp[finish][i]
        return dp[finish][fuel] % int(1e9+7)