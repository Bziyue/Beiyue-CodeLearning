#include <bits/stdc++.h>
using namespace std;
list<int> nodes;

int main()
{
    int n , m; cin>>n>>m;
    for(int i = 1; i <= n ; i++)
    {
        nodes.push_back(i);
    }

    auto now = nodes.begin();
    while((n--) > 1)
    {
        for(int i = 1 ; i < m ; i++) 
        {
            now++;
            if(now == nodes.end())
            {
                now = nodes.begin(); //形成循环链表
            }
        }
        cout<<*now<<" ";
        now = nodes.erase(now); //erase会返回被删除元素的下一个迭代器
        if(now == nodes.end()) //删除最后一个元素返回end
        {
            now = nodes.begin();
        }
    }

    cout<<*now<<endl;
    
    return 0;
}