# c++ 解法中的第二种解法 来写的
if __name__ == "__main__":
    data = [*open(0)]
    di = lambda x:map(int,data[x].split())
    n, d, m = *di(0),
    a = *di(1),
    l1 = []
    l2 = []
    for ai in a:
        if ai > m:
            l1.append(-ai)
        else:
            l2.append(-ai)
    l1.sort()
    l2.sort()
    ans = 0
    l1.insert(0,0)
    l2.insert(0,0)
    m1 = len(l1)
    m2 = len(l2)
    for i in range(1,m1): l1[i] = l1[i]+l1[i-1]
    for i in range(1,m2): l2[i] = l2[i]+l2[i-1]
    for i in range(m2):
        k = (m2 + m1-i+d - 2) // (d+1)
        if k<m1:
            ans = max(ans, -l1[k] - l2[i])
    print(ans)