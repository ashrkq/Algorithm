for s in [*open(0)][1:]:
  s = s[0:-1]
  a = 'a' + s, s + 'a'
  x, y = (t[::-1] == t for t in a)
  print(['YES ' + a[x], 'NO'][x&y])