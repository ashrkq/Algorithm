for s in[*open(0)][1:]:
    a=*map(int,s.split()),
    n=sum(x%2for x in a)
    print('YNeos'[n==2or n>2 and 0 in a[:3]::2])