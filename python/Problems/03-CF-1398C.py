# 思想类似c++ 代码进行了精简
if __name__ == "__main__":
    for data in [*open(0)][2::2]:
        d = {0:1}
        summ = ans = 0
        for a in data[0:-1]:
            c = int(a) - 1
            summ += c
            x = d.get(summ,0)
            d[summ] = x + 1
            ans += x
        print(ans)
