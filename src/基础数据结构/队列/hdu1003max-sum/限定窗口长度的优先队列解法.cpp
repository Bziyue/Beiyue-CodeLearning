#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int prefix[N];
int arr[N];
class Comp{
public:
    bool operator()(int i,int j)
    {
        //小根堆
        return prefix[i] > prefix[j];
    }
};
priority_queue<int,vector<int>,Comp> pq;
int main()
{
    int n,m;cin>>n>>m;
    for(int i = 1; i <= n;i++) cin>>arr[i];
    for(int i = 1; i <=n;i++) prefix[i] = prefix[i-1] + arr[i]; //计算前缀和

    int ans = numeric_limits<int>::min();
    pq.push(0);
    for(int i = 1; i <= n; i++)
    {
        //删去队首超过窗口范围的下标
        while(!pq.empty() && pq.top() < i - m) pq.pop();     //优先队列的做法有问题，会使得不在top的但不在窗口内的元素无法被移除，从而导致优先队列的排序出错，可能使得应该在top的元素不在top
        if(pq.empty())
        {
            ans = max(ans,prefix[i]); //如果队列为空了，以当前元素作为窗口的有效元素
        }
        else
        {
            //由于窗口队列头部存放了使得prefix[i] - prefix[k] 最小的下标，所以
            ans = max(ans, prefix[i] - prefix[pq.top()]);
        }

        //将i加入队尾
        pq.push(i);
    }


    cout<<ans<<endl;
}