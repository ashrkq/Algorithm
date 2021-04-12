#include<bits/stdc++.h>
using namespace std;
#define INF 300010
char *s;
int main () {
  s = (char*)malloc(sizeof(char) * INF);
  int T;  scanf("%d", &T);
  while (T--) {
    memset(s, 0, sizeof(char) * INF);
    scanf("%s", s);
    int len = strlen(s);
    int index = -1;
    for(int i=0; s[i]; i++) if(s[i] != 'a') index = i;
    if(index == -1) puts("NO");
    else{
      index = len - index - 1;
      puts("YES");
      for(int i=0; s[i]; i++){
        if(i == index) printf("%c", 'a');
        printf("%c", s[i]);
      }
      puts("");
    }
  }
  return 0;
}