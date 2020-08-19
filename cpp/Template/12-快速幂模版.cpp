#include<stdio.h>

int ppow(int a, int n){
    int ans =1,base = a;
    while (n) {
        if(n&1)
            ans*=base;
        base*=base;
        n>>=1;
    }
    return ans;
}
int main(){
    int a,b; scanf("%d %d",&a,&b);
    printf("%d\n",ppow(a,b));  // 快速求出a的b次方
    return 0;
}
