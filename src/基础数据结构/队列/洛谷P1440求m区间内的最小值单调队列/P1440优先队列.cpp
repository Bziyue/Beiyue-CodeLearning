#include <bits/stdc++.h>
using namespace std;

struct my_pair
{
    int idx;
    int num;
    my_pair(int idx,int num):idx(idx),num(num){};
    bool operator>(const my_pair &other)const
    {
        return this->num > other.num;
    }
    
};
priority_queue<my_pair,vector<my_pair>,greater<my_pair>> pq;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;

    for(int i = 1; i <= n; i++)
    {
        while(!pq.empty() && pq.top().idx < i - m) pq.pop();
        if(pq.empty()) cout<<0<<'\n';
        else cout<<pq.top().num<<'\n';

        int num;cin>>num;
        pq.emplace(i,num);
    }

    return 0;
}