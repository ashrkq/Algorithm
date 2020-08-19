#include <queue>
#include <stdio.h>
using namespace std;
int tree[2010000][26];
int next_tree[2010000];
int F[2010000];
char s[2001000];
int cnt = 0;
// AC自动机判断模式串中是否存在这个节点
void build_tree(){
    scanf("%s",s);
    int num = 0;
    // 构造字典树
    for(int i = 0;s[i];i++){
        int c = s[i] - 'a';
        if(!tree[num][c])
            tree[num][c] = ++cnt;
        num = tree[num][c];
    }
    F[num]++;
}
void build_next(){
    queue<int> q;
    next_tree[0] = 0;
    for(int i=0;i<26;i++){
        if(tree[0][i])
            q.push(tree[0][i]);
    }
    // 构造后缀数组
    // 如果存在这个数 字典树继续向下 后缀数组指向父亲节点的后缀接节点所指向的当前父亲节点
    // 如果不存在此字符指向父亲节点的后缀节点指向当前字符
    while(!q.empty()){
        int m = q.front();
        q.pop();
        for(int i = 0;i<26;i++){
            int u = tree[m][i];
            if(u){
                q.push(u);
                next_tree[u] = tree[next_tree[m]][i];
            }
            else
                tree[m][i] = tree[next_tree[m]][i];
        }

    }
}
int query(){
    scanf("%s",s);
    int num = 0;
    int ans = 0;
    for(int i=0;s[i];i++){
        num = tree[num][s[i] - 'a'];
        // 查找计算从第x个字符开始到达i的所有的后缀是否合格
        // 第x个字符可能再字典树的运行过程中自动的被换掉
        // 构造时自动把无法匹配到的字段跳转到可以匹配的字段去
        // 如果匹配不上就是0
        for(int j = num;j && F[j]!=-1;j=next_tree[j]){
            ans+=F[j];
            F[j] = -1;
        }
    }
    return ans;
}
int main(){
    int n; scanf("%d",&n);
    while(n--) build_tree();
    build_next();
    if(query()) printf("YES\n");
    else printf("NO\n");
    return 0;
}
