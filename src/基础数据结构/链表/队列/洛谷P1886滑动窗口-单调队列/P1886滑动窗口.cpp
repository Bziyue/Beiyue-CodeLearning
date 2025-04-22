#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
using ll = long long;
ll arr[N] = {};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int min_num_idx = 0;
    int max_num_idx = 0;
    vector<ll> min_arr, max_arr;
    // 定义长度为k的滑动窗口
    vector<int> window(k + 1);
    for (int i = 1; i <= k; i++)
    {
        window[i] = i; // 初始化滑动窗口下标
    }

    for (int i = 0; window[k] + i <= n; i++)
    {
        // 如果记录的最小数和最大数的下标已经超出窗口范围，那么重新寻找最小数和最大数
        if (min_num_idx < window[1] + i)
        {
            ll min_num = arr[window[1] + i]; // 初始化为窗口第一个元素

            min_num_idx = window[1] + i;

            for (int j = 1; j <= k; j++) // 在窗口范围内寻找最大最小值 1 到 k
            {
                if (arr[window[j] + i] <= min_num) //改为小于等于和大于等于，因为使用小于符号面对超大输入，并且输入全同会导致指针固定在窗口的起点
                {                                                       //导致每次滑动窗口都会重新计算 
                    min_num = arr[window[j] + i];    //并且如果有相同的最大值和最小值，这种方式也可以将idx尽可能的往后放，从而避免多次调用
                    min_num_idx = window[j] + i;
                }
            }
        }

        if (max_num_idx < window[1] + i)
        {
            ll max_num = arr[window[1] + i];
            max_num_idx = window[1] + i;
            for (int j = 1; j <= k; j++) // 在窗口范围内寻找最大最小值 1 到 k
            {

                if (arr[window[j] + i] >= max_num) //
                {
                    max_num = arr[window[j] + i];
                    max_num_idx = window[j] + i;
                }
            }
        }
        // 比较窗口k元素和最小最大值
        if (arr[window[k] + i] <= arr[min_num_idx]) //同样是尽可能将指针后靠，避免离开窗口
            min_num_idx = window[k] + i;
        if (arr[window[k] + i] >= arr[max_num_idx])
            max_num_idx = window[k] + i;

        min_arr.push_back(arr[min_num_idx]);
        max_arr.push_back(arr[max_num_idx]);
    }

    for(auto num:min_arr) cout<<num<<" ";
    cout<<'\n';
    for(auto num:max_arr) cout<<num<<" ";
    cout<<endl;

    return 0;
}