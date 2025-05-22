#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int prefix[N];
int arr[N];
deque<int> dq;
int main()
{
    int n,m;cin>>n>>m;
    for(int i = 1; i <= n;i++) cin>>arr[i];
    for(int i = 1; i <=n;i++) prefix[i] = prefix[i-1] + arr[i]; //计算前缀和

    int ans = numeric_limits<int>::min();
    dq.push_back(0); //以便计算第一个s[i] 对应的ins
    for(int i = 1; i <= n; i++)
    {
        //删去队首超过窗口范围的下标
        while(!dq.empty() && dq.front() < i - m) dq.pop_front();
        if(dq.empty())
        {
            ans = max(ans,prefix[i]); //如果队列为空了，以当前元素作为窗口的有效元素
        }
        else
        {
            //由于窗口队列头部存放了使得prefix[i] - prefix[k] 最小的下标，所以
            ans = max(ans, prefix[i] - prefix[dq.front()]);
        }

        //除去窗口尾部大于prefix的元素, 将小的放在前面才能使得prefix[i] - prefix[k]尽可能大
        while(!dq.empty() && prefix[dq.back()] >= prefix[i]) dq.pop_back();

        //将i加入队尾
        dq.push_back(i);
    }


    cout<<ans<<endl;
}