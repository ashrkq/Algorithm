# c++ 解法中的第二种解法 来写的
if __name__ == "__main__":
    data = [*open(0)]
    di = lambda x:map(int,data[x].split())
    n, d, m = *di(0),
    a = *di(1),
    l1 = [0]
    l2 = [0]
    for ai in a:
        if ai > m:
            l1.append(-ai)
        else:
            l2.append(-ai)
    # 存放了-的元素可以直接选择使用从小到大排序
    l1.sort()
    l2.sort()
    ans = 0
    m1 = len(l1)
    m2 = len(l2)
    for i in range(m2):
        k = (m2 + m1-i+d) // (d+1)
        if k<=m1:
            ans = max(ans, -l1[k] - l2[i])
    print(ans)