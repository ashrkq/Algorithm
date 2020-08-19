int sum[1001000];
int low_bit(int x){ return x&-x; }
void uppdata(int x){
    while(x<=1000000){
        sum[x]++;
        x += low_bit(x);
    }
}
int Sum(int x){
    int ans = 0;
    uppdata(x);
    x--;
    while(x){
        ans += sum[x];
        x -= low_bit(x);
    }
    return ans;
}
int* countSmaller(int* nums, int numsSize, int* returnSize){
    printf("sadasda");
    memset(sum,0,sizeof(sum));
    for(int i = numsSize-1;i>=0;i--){
        
        nums[i] =  Sum(nums[i]+500000);
    }
    *returnSize = numsSize;
    return nums;
}
int main(){
    
}
