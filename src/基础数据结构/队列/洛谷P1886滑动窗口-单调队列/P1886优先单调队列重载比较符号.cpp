#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int arr[N] = {0};




struct data_idx{
    int data;
    int idx;
};
bool operator<(const data_idx& data_idx1 ,const data_idx& data_idx2) //重载小于符号，在less中自动调用
{                                                                                               //如果不是传值，而是传递引用，那么需要加上const修饰符，因为在stl的实现内部要求使用const
    if(data_idx1.data < data_idx2.data) return true;                    //在STL实现内部，greater less内部使用比较符号等不改变值的操作时，重载比较函数并传入引用时，需要加上const修饰符，表明重载的函数不会改变传入的值；如果时结构体或对象内部的函数，要在大括号前加上const修饰符。
    else return false;
}
bool operator>(const data_idx& data_idx1 ,const  data_idx& data_idx2) // 重载大于符号，在greater中自动调用
{
    if(data_idx1.data > data_idx2.data) return true;
    else return false;
}

priority_queue<data_idx , vector<data_idx> , greater<data_idx> > pq1; //传入greater 变为小根堆
// priority_queue<data_idx , vector<data_idx>  , less<data_idx>> pq2;
priority_queue<data_idx , vector<data_idx>> pq2;
int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , k ; cin >> n >> k ;
    for(int i = 1; i <= n; i ++) cin>>arr[i];

    for(int i = 1; i <= n ; i ++)
    {
        data_idx temp;
        temp.data = arr[i];
        temp.idx = i;
        pq1.push(temp); //自动把最小的元素放到对头
        if(i >= k)
        {
            while(!pq1.empty() && pq1.top().idx <= i - k) pq1.pop(); //除去超出范围的对头
            cout << arr[pq1.top().idx] <<" ";
        }
    }
    cout << '\n';

    for(int i = 1; i <= n ; i ++)
    {
        data_idx temp;
        temp.data = arr[i];
        temp.idx = i;
        pq2.push(temp); //自动把最大的元素放到对头
        if(i >= k)
        {
            while(!pq2.empty() && pq2.top().idx <= i - k) pq2.pop(); //除去超出范围的对头
            cout << arr[pq2.top().idx] <<" ";
        }
    }
    
    cout << endl;

    return 0;
}