#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int nodes[N];
int main()
{
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , m; cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        nodes[i] = i+1;
    }
    nodes[n] = 1;  //形成循环链表
    int now = 1;
    int prev = n;
    while((n--) > 1)
    {
        for(int i = 1; i < m; i++)
        {
            prev = now;
            now = nodes[now]; //移动到下一个节点
        }
        //输出
        cout<<now<<" ";
        //跳过当前节点，now的前一个节点的指针指向now的下一个节点
        nodes[prev] = nodes[now];
        now = nodes[now];//移动到下一个节点 prev不变，只改变prev所在节点的指向

    }

    cout<<now<<endl;
    return 0;
}