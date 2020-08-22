# 异或的性质
if __name__ == "__main__":
    data = [*open(0)]
    dt = lambda x:map(int,data[x].split())
    a = *dt(1),
    b = *dt(2),
    for k in range(512):
        for ai in a:
            flag = False
            for bi in b:
                if (k|(ai&bi)) == k:
                    flag = True
                    
                    break
            if not flag: break  # 没有找到满足k这个模式的的字符直接结束
        else: break # 对于所有的i都可以找到满足k这个模式的数字直接结束
    print(k)
