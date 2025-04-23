#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int arr[N] = {0};
deque<int> dq;
int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k ; cin >> n >> k ;
    for(int i = 1; i <= n; i ++) cin>>arr[i];

    for(int i = 1; i <= n ; i ++)
    {
        while(!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back(); //如果当前元素大于队尾元素，除去队尾元素
                                                                                                        //直到前面没有比他更小的 最小元素放到对头
        dq.push_back(i);
        //推入k个元素后才能开始输出，窗口需要完全覆盖数组
        if(i >= k)
        {
            //如果对头元素的idx超出窗口范围，那么去头
            //窗口第一个元素是i - k + 1;
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            cout << arr[dq.front()] << " ";
        }
    }
    cout<<'\n';
    dq.clear();
    for(int i = 1; i <= n ; i ++)
    {
        while(!dq.empty() && arr[dq.back()]  < arr[i] ) dq.pop_back(); //如果当前元素队尾元素，除去队尾元素
                                                                                                        //直到前面没有比他更大的 将最大元素放到队头
        dq.push_back(i);
        //推入k个元素后才能开始输出，窗口需要完全覆盖数组
        if(i >= k)
        {
            //如果对头元素的idx超出窗口范围，那么去头
            //窗口第一个元素是i - k + 1;
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            cout << arr[dq.front()] << " ";
        }
    }
    cout<<endl;

    return 0;
}