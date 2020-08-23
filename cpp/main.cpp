#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL, LL>m;
LL ans;
LL summ;
string s;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        m.clear();
        ans = 0; summ = 0;
        int n; scanf("%d",&n);
        cin>>s; m[0] = 1;
        for(int i=0;i<s.size();i++){
            int k = s[i] - '1';
            summ+=k;  ans += m[summ];  m[summ]++;
        }
        printf("%lld\n", ans);

    }
    return 0;
}