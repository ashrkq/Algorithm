#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<string, int>m;
int *pre;
// 查找祖先然后路径压缩
int find(int k){
    return pre[k] = (pre[k]==k?k:find(pre[k]));
}
// 判断两个人是否属于同一祖先
void merge(int x, int y){
    int xx = find(x), yy = find(y);
    if(xx != yy )pre[xx] = yy;
}
// 初始化设置 每个人的祖先都是自己
void init(int n){
    pre = (int*)malloc(sizeof(int)*(n+1));
    for(int i=1;i<=n;i++) pre[i] = i;
}
int main(){
    int n; cin>>n;
    int id = 0;
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
            // 如果不存在就直接表示不在同一组织内
            if(k1==0 || k2 == 0) {puts("no"); continue;}
            if(find(k1) == find(k2))
                puts("yes");
            else
                puts("no");
        }
    }
    return 0;
}