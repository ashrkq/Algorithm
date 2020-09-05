# 第一次使用python写DFS
class Solution:
    xt = [1,-1,0,0]
    yt = [0,0,1,-1]
    def DFS(self, x, y, grid, n, m):
        self.vis[x][y] = 1
        summ = 1
        for i in range(4):
            xx = x + self.xt[i]
            yy = y + self.yt[i]
            if xx < 0 or xx >=n or yy < 0 or yy >= m or grid[xx][yy] == 0 or self.vis[xx][yy]:
                continue

            summ += self.DFS(xx, yy, grid, n, m)
        return summ

    def minDays(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        summ = 0
        for j in range(m):
            s = 0
            for i in range(n):
                summ += grid[i][j]
                if grid[i][j]:
                    x, y = i, j
        self.vis = [[0 for i in range(m)] for i in range(n)]
        s = self.DFS(x, y, grid, n, m)
        if summ == 1:
            return 1
        if s != summ:
            return 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0: continue
                grid[i][j] = 0
                self.vis = [[0 for i in range(m)] for i in range(n)] 
                s = self.DFS(x, y, grid, n, m)
                if s != summ -1:
                    return 1
                grid[i][j] = 1
                x, y = i, j
        return 2