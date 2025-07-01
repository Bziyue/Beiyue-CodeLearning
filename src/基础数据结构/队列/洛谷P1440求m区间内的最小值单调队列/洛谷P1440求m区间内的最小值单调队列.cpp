#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int arr[N];
deque<int> dq;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin >> n >> m;
    for(int i = 1; i <= n; i++) cin>>arr[i];
    for(int i = 1; i <= n; i++)
    {

        //去除超过窗口范围的元素
        while(!dq.empty() && dq.front() < i - m) dq.pop_front(); //由于窗口不包含 i 所有是i -k , i 在窗口前一个（从左到右）

        if(dq.empty()) cout<<0<<endl;
        else
        {
            cout<<arr[dq.front()]<<'\n';
        }

        while(!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();

        dq.push_back(i);
    }


    return 0;
}