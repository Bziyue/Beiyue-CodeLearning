#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int arr[N];
int prefix[N];

//目标 最大化 prefix[i]-prefix[k] 
//ans = max(ans, prefix[i] - prefix[k]) 
//使用单调队列将最小的prefix[k] 固定在对头
struct comp
{
    bool operator()(const int& a,const int& b)
    {
        return prefix[a] > prefix[b];  
    }
};
priority_queue<int,vector<int>,comp> pq;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;

    for(int i = 1; i <= n; i ++)
    {
        cin>>arr[i];prefix[i] = arr[i] + prefix[i-1];
    }

    int ans = arr[1];pq.push(0);
    
    for(int i =1; i <= n;i++)
    {
        while(!pq.empty() && pq.top() < i - m) pq.pop();
        ans = max(ans,prefix[i] - prefix[pq.top()]);
        pq.push(i);
    }

    cout<<ans<<endl;

    return 0;


}