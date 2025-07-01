#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int arr[N];
deque<int> dq;

int main()
{
    int n , k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin>>arr[i];

    for(int i = 1; i <= n; i++)
    {
        while(!dq.empty() && dq.front() <= i -k ) dq.pop_front();

        //注意和1440的区别 输出窗口内，包含arr[i] 1440是arr[i] 之前 所有这里先入队再输出

        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back(); //维持最大的在对头

        dq.push_back(i);

        if(i >= k) cout<<arr[dq.front()]<<'\n';
    }


    return 0;
}