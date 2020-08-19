import math


# 梯度下降算法
# 对于一个函数满足是一个凸函数的情况下
# 每次选取一定的步长进行梯度下降  直到这个步长变得无法下降为止 更新步长
# 然后继续进行梯度下降
# 直到误差达到控制范围内 Python代码
class Solution:
   def getMinDistSum(self, positions: list[list[int]]) -> float:
       disp = ((0, 1), (0, -1), (1, 0), (-1, 0))
       stape = 1.0
       esp = 1e-7
       dis = 5e-1

       n = len(positions)
       x = sum(po[0] for po in positions) / n
       y = sum(po[1] for po in positions) / n
       # 计算欧几里得距离的函数
       get_dis = lambda x, y: sum(math.sqrt((x - p[0]) ** 2 + (y - p[1]) ** 2) for p in positions)
       # 进行梯度的下降
       while stape > esp:
           K = True
           for xd, yd in disp:
               xx, yy = x + xd * stape, y + yd * stape
               if get_dis(xx, yy) < get_dis(x, y):
                   x, y = xx, yy
                   K = False
                   break
           if K:
               stape *= 1 - dis

       return get_dis(x, y)
