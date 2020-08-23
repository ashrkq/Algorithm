#include<bits/stdc++.h>
using namespace std;
// 一个很简单的问题被想复杂了
// 求出 R -> L 的和正好等等于 R - L + 1
// 表示这段区间中每个元素的平均值就是1
// 把这个区间的每个元素-1就可以得出我们需要的其实是一个和为0的区间
// 记录前n个数的和就可以的到 每次找到前面和自己一样大的数有几个就行了
// 记得0 初始化为1 时间复杂度是O(n) 
#define LL long long
map<LL,LL> m;
LL ans;
LL summ;
string s;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        ans = 0; summ = 0; m.clear();
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