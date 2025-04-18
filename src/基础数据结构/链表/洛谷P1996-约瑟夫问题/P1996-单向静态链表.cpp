#include <bits/stdc++.h>
using namespace std;

const int N = 105;
class node
{
public:
    int id;
    int next_id;
    int data;
};
node nodes[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n,m; cin>>n>>m;

    nodes[0].data=0;
    nodes[0].id = 0;
    nodes[0].next_id=1;
    for(int i = 1;i <= n ;i++)
    {
       nodes[i].data = i;
       nodes[i].id  = i;
       nodes[i].next_id = i+1;
    }
    //让最后一个节点指向第一个节点，形成循环链表
    nodes[n].next_id = 1;

    int now = 1;
    int prev = n;
    while((n--) > 1)
    {
        for(int i = 1;i < m;i++)
        {
            prev = now; //now后移，所以prev指向当前now
            now = nodes[now].next_id;  //now后移
        }
        cout<<nodes[now].data<<" ";
        nodes[prev].next_id = nodes[now].next_id; //当前节点的前一个节点的next_id 指向now的下一个，也即跳过当前now
        now = nodes[prev].next_id; //now为下一个节点
    }
    cout<<nodes[now].data<<endl;

    return 0;
}