#include <deque>
#include <iostream>
using namespace std;
const int N = 2e6+5;
int arr[N];
int prefix[N];
deque<int> dq;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    //断环为链
    for(int i = 1; i <= n-1; i++)
    {
        arr[n+i] = arr[i];
    }
    //构造前缀和
    for(int i = 1; i <= 2*n-1; i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }

    //在1 2 3 ... n 1 2 3 ... n-1 的前缀和数组中构建长度为 n 的滑动窗口
    //要让汇报大于等于0，那意味着在 k 到 k + n - 1范围内的 所以i 有 k 到  i 求和大于等于0
    //区间求和问题可以用前缀和快速求解 prefix[i] - prefix[k-1] 代表 k 到 i 的区间和
    //从而，问题转换为 k 到 k + n -1 的区间内，是否会有前缀和 prefix[i] - prefix[k-1] 小于0
    //那么很显然，只要最小的 prefix[i] 满足 prefix[i] - prefix[k-1] 大于等于0，那么其他所有的 i 都满足
    //所有问题就是 在 1 2 3 ... n 1 2 3 ... n-1 的前缀和数组中构造一个滑动窗口，滑动的过程中维护一个单调队列，对头是最小 prefix[i] 
    //每次检查 对头的 prefix[i] - prefix[k-1] 是否大于等于0
    int ans = 0;
    for(int i = 1; i <= 2*n -1 ; i++)
    {
        //维护单调队列 推出超过窗口的元素
        // i - n 表示窗口的前一个元素
        while(!dq.empty() && dq.front() <= i - n) dq.pop_front();

        //维护窗口的单调性
        while(!dq.empty() && prefix[dq.back()] >= prefix[i]) dq.pop_back();
        dq.push_back(i);

        //在形成的窗口中进行检查

        if(i >= n)
        {
            // k = i - n +1 故 k 的前一个为 i - n
            if(prefix[dq.front()] - prefix[i - n] >= 0) ans++;
        }
        
    }

    cout<<ans<<endl;

    return 0;
}