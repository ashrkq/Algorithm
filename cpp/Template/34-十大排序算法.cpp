#include <bits/stdc++.h>
using namespace std;
class Ordering
{
public:
    // 冒泡排序
    static void bubble_sort(vector<int> &arr)
    {
        // 冒泡排序 每次选择一个比较前n-i个元素然后把最大的放到最后面
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n - 1 - i; j++)
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    count++;
                }
            // 优化方式 没有变化就说明已经有序了
            if (count == 0)
                return;
        }
    }
    // 选择排序
    static void selection_sort(vector<int> &arr)
    {
        // 选择排序思想类似冒泡排序 只是不进行每次交换了每次直只知道最小的只交换一次
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int temp = i;
            for (int j = i + 1; j < n; j++)
                if (arr[temp] > arr[j])
                    temp = j;
            swap(arr[temp], arr[i]);
        }
    }
    // 插入排序
    static void insertion_sort(vector<int> &arr)
    {
        // 插入排序每次选择下一个元素其他元素整体后移到一个小于等于当前元素的位置停止后移
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int t = arr[i], j = i - 1;
            while (j >= 0 && arr[j] > t)
                arr[j + 1] = arr[j], j--;
            arr[j + 1] = t;
        }
    }
    // 希尔排序
    static void shell_sort(vector<int> &arr)
    {
        // 希尔排序 每次对插入排序的间隔进行限制 每次二分这个间隔 插入排序越是有序越是时间复杂度低
        // 每次都使序列比原来更有序
        int n = arr.size();
        int k = n / 2;
        while (k)
        {
            for (int i = k; i < n; i++)
            {
                int j = i, t = arr[i];
                while (j - k >= 0 && t < arr[j - k])
                    arr[j] = arr[j - k], j -= k;
                arr[j] = t;
            }
            k /= 2;
        }
    }
    // 归并排序
    static void merge_sort(vector<int> &arr)
    {
        // 归并排序 时间复杂对最多是O(n*log(n)) 每次把集合分成两份得到两个有序的序列然后以O(n) 进行合并
        // 最多分割log(n) 次
        int n = arr.size();
        if (n < 2)
            return;
        int mid = n / 2;
        vector<int> arrl(arr.begin(), arr.begin() + mid);
        vector<int> arrr(arr.begin() + mid, arr.end());
        merge_sort(arrl);
        merge_sort(arrr);
        int l = 0, r = 0, ln = arrl.size(), rn = arrr.size();
        arr.clear();
        while (l < ln || r < rn)
        {
            if (l < ln && r < rn)
            {
                if (arrl[l] <= arrr[r])
                    arr.push_back(arrl[l]), l++;
                else
                    arr.push_back(arrr[r]), r++;
            }
            else if (l < ln)
                arr.push_back(arrl[l]), l++;
            else
                arr.push_back(arrr[r]), r++;
        }
    }
    // 快速排序
    static void quick_sort(vector<int> &arr)
    {
        // 基本思想把比一个元素大的放在一边小的放在另一个边 递归

        int n = arr.size();
        if (n < 2)
            return;
        int num = arr[0];
        vector<int> arrl;
        vector<int> arrr;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= num)
                arrr.push_back(arr[i]);
            else
                arrl.push_back(arr[i]);
        }
        quick_sort(arrr);
        quick_sort(arrl);
        arr.clear();
        for (int a : arrl)
            arr.push_back(a);
        arr.push_back(num);
        for (int a : arrr)
            arr.push_back(a);
    }
};
// 对排序函数的调用
template <class T>
void test_sort(T &ordering, vector<int> &arr, int len)
{
    clock_t startTime, endTime;
    srand((int)time(0));
    arr.clear();
    for (int i = 0; i < 20; ++i)
        arr.push_back(rand() % 100);
    for (int a : arr)
        printf("%d ", a);
    puts("");
    ordering(arr);
    for (int a : arr)
        printf("%d ", a);
    puts("");
    arr.clear();
    for (int i = 0; i < len; ++i)
        arr.push_back(rand());
    startTime = clock();
    ordering(arr);
    endTime = clock();
    cout << "The run " << len << "数据 time is: " << (endTime - startTime) / 1000 << "ms" << endl;
}

int main()
{
    Ordering ordering = Ordering();
    vector<int> arr;
    printf("-------------冒泡排序--------------\n");
    test_sort(ordering.bubble_sort, arr, 10000);
    printf("-------------选择排序--------------\n");
    test_sort(ordering.selection_sort, arr, 10000);
    printf("-------------插入排序--------------\n");
    test_sort(ordering.insertion_sort, arr, 10000);
    printf("-------------希尔排序--------------\n");
    test_sort(ordering.shell_sort, arr, 1000000);
    printf("-------------归并排序--------------\n");
    test_sort(ordering.merge_sort, arr, 100000);
    printf("-------------快速排序--------------\n");
    test_sort(ordering.quick_sort, arr, 100000);
    return 0;
}