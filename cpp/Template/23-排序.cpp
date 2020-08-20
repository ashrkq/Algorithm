#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct datanumNum{
    long long a;
    int b;
    int d;
    const bool operator < (const datanumNum &y) const{
        if(this->a<0 && y.a<0){
            if(this->b == -1 && y.b == -1)
                return this->a < y.a;
            if(this->b == -1 || y.b == -1)
                return this->b == -1;
            return this->b < y.b;
        }
        if(this->a<0 || y.a<0)
            return y.a<0;
        if(this->b == -1 && y.b == -1)
            return this->a < y.a;
        if(this->b == -1 || y.b == -1)
            return y.b == -1;
        return this->b < y.b;
    }

}datanum[200010];
int p[200010];
long long sum[200010];
int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n;i++){ scanf("%lld", &datanum[i].a); datanum[i].d=i; }
    for(int i=1; i<=n;i++) scanf("%d", &datanum[i].b);
    sort(datanum+1,datanum+n+1);
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        datanum[i].a += sum[datanum[i].d];
        printf("%3lld ",datanum[i].a);
        p[i] = datanum[i].d;
        ans += datanum[i].a;
        if(datanum[i].b != -1) sum[datanum[i].b] += datanum[i].a;
    }
    puts("");
    for(long long i=1;i<=n;i++){
        printf("%3d ",datanum[i].b);
    }
    puts("");
    for(long long i=1;i<=n;i++){
        printf("%3d ",datanum[i].d);
    }
    puts("");
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    return 0;
}
