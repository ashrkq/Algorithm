// hiho第一周 对于最长回文子串的研究
// 通过优化从n^3 -> n^2 -> n 的时间优化
// 理解字符串的特性
#include<stdio.h>
#include<string.h>
char a[2001000];
char b[4001000];
int num[4000100];
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a>b?b:a;
}
int ac1(){
    // 暴力找到所有的字串

    int maxx = 1;
    scanf("%s",a);
    for(int i = 0;a[i]; i++){
        for(int j = i + 1; a[j]; j++){
            int num = 0;
            for(int k = 0; k<= (j-i)/2; k++){
                if(a[i+k] == a[j-k]) num++;
                else break;
            }
            if( (j - i ) & 1 ) num = num*2;
            else num = num * 2 - 1;
            if(num > maxx) maxx = num;
        }
    }
    return maxx;
}
int ac2(){
    // 枚举所有的字串的时候只枚举每个中心点
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int maxx = 1;
    int n = 0;
    scanf("%s",a);
    for(int i = 0, j = 0;a[i]; i++,j+=2){
        b[j] = ' ';b[j+1] = a[i];
        n += 2;
    }
    b[n] = ' ';
    printf("%s123123123\n",b);
    for(int i = 0; b[i]; i++){
        int num = 0;
        for(int j = i; j>= 0; j--){
            if(b[j] == b[i+i-j]) num++;
            else break;
        }
        if(num >= maxx) maxx = num-1;
        printf("%d****%d······%d\n",i,num,maxx);
    }
    return maxx;
}
int ac3(){
    // 查找最长回文子串
    int maxx = 1;
    int n = 0;
    scanf("%s",a);
    for(int i = 0, j = 0;a[i]; i++,j+=2){
        b[j] = ' ';b[j+1] = a[i];
        n += 2;
        num[j] = 1;
        num[j+1] = 1;
    }
    b[n] = ' ';
    b[n+1] = '*'; num[n] = 1;
    int id = 0; // num[id] + id 表示最长一个会文串的末尾
    // 一个已经找的了一个够长的回文串的时候我们可以
    // 我们使用num记录了所有数最大的回文数的右端
    // 我们可以计算出他所有右端的数的最小值
    // 就是和这个数对称的值和到最右端的距离中的最小值
    // 我们使用id维护哪个可以到达的最右端的值
    for(int i = 0; i<=n; i++){
        if(num[id]+id > num[i])
            num[i] = min(num[id+id-i], num[id]+id-i);
        while(b[i+num[i]] == b[i-num[i]])
            num[i]++;
//        for(int j = i + num[i]; j <= i*2; j++){
//            if(b[j] == b[i+i-j])
//                num[i]++;
//            else break;
//        }
//        printf("%d %d\n",i,num[i]);
        if (num[i]+i > num[id]+id)
                id = i;
        if(num[i] > maxx) maxx = num[i] - 1;
    }
    return maxx;
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        printf("%d\n",ac3());
    }
    return 0;

}
