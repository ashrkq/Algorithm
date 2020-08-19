#include<stdio.h>
#include<string.h>
int tree[400100][30];
int sum[400010];
char s[1000];
int num;
// 字典树 每个节点有26个分叉维护每个节点的值就行了
void build(){
    int m = 0;
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(!tree[m][s[i]-'a'])
            tree[m][s[i]-'a']=++num;
        m = tree[m][s[i]-'a'];
        sum[m]++;
    }
}
int quire(){
    int m = 0;
    scanf("%s",s);
    for(int i=0;s[i];i++){
        if(tree[m][s[i]-'a'])
            m = tree[m][s[i]-'a'];
        else
            return 0;
    }
    return sum[m];
}
int main(){
    int n,m;
    num = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) build();
    scanf("%d",&m);
    for(int i=0;i<m;i++) printf("%d\n",quire());
    return 0;
}
