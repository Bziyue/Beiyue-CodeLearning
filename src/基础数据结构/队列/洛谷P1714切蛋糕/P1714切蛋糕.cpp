#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int arr[N];
int prefix[N];

//目标 最大化 prefix[i]-prefix[k] 
//ans = max(ans, prefix[i] - prefix[k]) 
//使用单调队列将最小的prefix[k] 固定在对头
deque<int> dq;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;

    for(int i = 1; i <= n; i ++)
    {
        cin>>arr[i];prefix[i] = arr[i] + prefix[i-1];
    }

    int ans = arr[1];
    dq.push_back(0);    //加入0元素 才能在窗口长度等于输入长度时正确判断 覆盖整个输入数组
    for(int i = 1; i <= n; i++)
    {
        //删除超出窗口范围的元素
        while(!dq.empty() && dq.front() < i-m) dq.pop_front();

        //找到最大的prefix[i]-prefix[k] 
        if(!dq.empty()) ans = max(ans, prefix[i] - prefix[dq.front()]);  //因为这里用到了 i 所以前面可以将小于i -m的元素删去

        //去尾部

        while(!dq.empty() && prefix[dq.back()] >= prefix[i]) dq.pop_back();

        dq.push_back(i);
    }

    cout<<ans<<endl;

    return 0;


}