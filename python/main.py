if __name__ == "__main__":
    data = [*open(0)]
    dt = lambda x:map(int,data[x].split())
    n,m = *dt(0),
    a = *dt(1),
    b = *dt(2),
    ans = 0
    c = [0 for i in range(n)]
    for k in range(n):
        mint = (0,0)
        for i,ai in enumerate(a):
            if c[i]: continue
            maxx = ai|ans
            for bi in b:
                maxx = min(maxx, ai&(bi|ans))
            mint = mint if mint[1]>maxx else (i,maxx)
        ans = mint[1]|ans
        c[mint[0]] = 1
    print(ans)
