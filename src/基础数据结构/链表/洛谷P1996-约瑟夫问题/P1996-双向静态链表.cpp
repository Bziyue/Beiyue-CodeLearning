#include <bits/stdc++.h>
using namespace std;
const int N = 105;
class node
{
public:
    int data;
    int prev_id, next_id;
    int id;
};
node nodes[N];
int main()
{
   int n , m; cin >> n >> m;
   int prev , now;
   
   for(int i = 1; i <= n; i++)
   {
        nodes[i].id = i;
        nodes[i].prev_id = i-1;
        nodes[i].next_id = i+1;
        nodes[i].data = i;
   }

   //形成双向循环链表
   nodes[1].prev_id = n;
   nodes[n].next_id = 1;

   now = 1;prev = n;
   while ((n--) > 1)
   {
        for(int i = 1; i < m; i++)
        {
            prev = now;
            now = nodes[now].next_id;
        }
        cout<<nodes[now].id<<" ";
        //从双向链表中删除当前节点
        //当前节点的上一个节点的next_id 跳过 now
        nodes[prev].next_id = nodes[now].next_id;
        //当前节点的下一个节点的prev_id跳过now
        nodes[nodes[now].next_id].prev_id = nodes[now].prev_id;

        //后移now
        now = nodes[now].next_id;
   }

   cout << nodes[now].id <<endl;
   
   
    return 0;
}