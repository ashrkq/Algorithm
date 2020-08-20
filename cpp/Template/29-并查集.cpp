#include<bits/stdc++.h>
using namespace std;
int id;
map<string, int>m;
int pre[100010];
int find(int k){
    return pre[k] = pre[k]==k?k:find(pre[k]);
}
void merge(int x, int y){
    int xx = find(x), yy = find(y);
    if(xx != yy )pre[xx] = yy;
}
void init(int n){
    for(int i=1;i<=n;i++) pre[i] = i;
}
int main(){
    int n; cin>>n;
    string s1, s2; init(n);
    for(int i=0;i<n;i++){
        int op; cin>>op>>s1>>s2;
        if(op == 0){
            if(!m[s1]) m[s1] = ++id;
            if(!m[s2]) m[s2] = ++id;
            int k1 = m[s1], k2 = m[s2];
            merge(k1, k2);
        }
        else{
            int k1 = m[s1], k2 = m[s2];
            if(find(k1) == find(k2))
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}