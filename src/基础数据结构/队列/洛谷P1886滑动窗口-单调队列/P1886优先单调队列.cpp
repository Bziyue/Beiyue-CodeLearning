#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int arr[N] = {0};

class Comp1{
public:
    bool operator()(int idx1, int idx2) //重载括号，进行自定义比较，生成小根堆
    {
        if(arr[idx1]  > arr[idx2]) return true;
        else return false;
    }
};

class Comp2{
    public:
        bool operator()(int idx1, int idx2)
        {
            if(arr[idx1]  < arr[idx2]) return true;
            else return false;
        }
    };
priority_queue<int , vector<int> ,Comp1> pq1;
priority_queue<int , vector<int> ,Comp2> pq2;

int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k ; cin >> n >> k ;
    for(int i = 1; i <= n; i ++) cin>>arr[i];

    for(int i = 1; i <= n ; i ++)
    {
        pq1.push(i); //自动把最小的元素放到对头
        if(i >= k)
        {
            while(!pq1.empty() && pq1.top() <= i - k) pq1.pop(); //除去超出范围的对头
            cout << arr[pq1.top()] <<" ";
        }
    }
    cout << '\n';

    for(int i = 1; i <= n ; i ++)
    {
        pq2.push(i); //自动把最大的元素放到对头
        if(i >= k)
        {
            while(!pq2.empty() && pq2.top() <= i - k) pq2.pop(); //除去超出范围的对头
            cout << arr[pq2.top()] <<" ";
        }
    }
    
    cout << endl;

    return 0;
}