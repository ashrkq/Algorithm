#include<bits/stdc++.h>
using namespace std;
#define LL long long
// 把数据分成两组第一组是小于等于m的 另外一组是大于m的
// 从小到大排序 每种
LL l1[100010];
LL l2[100010];
int m1,m2;
LL ans;
int d,n,m;
// 看到了别人的解法 假设选择i个小于m的 
// 所剩的天数 就是m1+m2-i+d
// 所需要的大于m的个数就是(m1+m2-i+d)/d+1 每个大于m的都会占用 d+1天
// 向下取整多出来的天数在后面会根据i的增加而补上
// 看看需要的个数是否小于等于拥有的个数就可以了
// if的内部居然也可以写表达式
void slove2(){
    for(int i=1;i<=m1;i++) l1[i] += l1[i-1];
    for(int i=1;i<=m2;i++) l2[i] += l2[i-1];
    int k = 0;
    for(int i=0;i<=m2;i++)
        if((k=(m1+m2-i+d)/(d+1)) <= m1)
            ans = max(ans, l1[k] + l2[i]);
    printf("%lld\n", ans);
}
// 我的解法
// 对于小于m元素一个求出前k项的和
// 每到一天可以计算选择一个大于m的看看是否满足在d+1天中小于m的和是否大于此元素
// 如果大于就选择最大的然后继续，记得最后需要保留一个大于的放在最后一天
void slove1(){
    for(int i=1;i<=m2;i++)l2[i]+=l2[i-1];
    int day = 1, k1 = 1, k2 = 1; 
    while(day<=n){
        LL maxx = -1;
        LL maxx2 = -1;
        if(k2+d <= m2) maxx2 = l2[k2+d]- l2[k2-1];
        else maxx2  = l2[m2] - l2[k2-1];
        if(k1 <= m1) maxx = l1[k1];
        if(maxx!=-1 && maxx >= maxx2 && (day + d + 1 <= n || day ==n || k2 > m2)&&(k1<m1||day==n))
            k1++, ans += maxx,day += d+1;
        else{
            ans += l2[k2] - l2[k2-1];
            k2++; day++;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d %d %d", &n,&d,&m);
    for(int i=1;i<=n;i++){ 
        int a; scanf("%d", &a);
        if(a>m) l1[++m1] = a;
        else l2[++m2] = a;
    }
    sort(l1+1,l1+m1+1,greater<LL>()); sort(l2+1,l2+m2+1,greater<LL>());
    slove2();
    return 0;
}