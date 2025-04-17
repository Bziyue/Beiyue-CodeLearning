#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};

int main()
{
    int n,m;cin>>n>>m;
    node * p , * now , * prev , * head; //用于存储当前位置，前一个位置。
    head = new node;
    head->next = NULL;
    head->data = 1;
    now = head;
    
    for(int i=2; i <= n; i++)
    {
        p = new node;
        p->data = i;
        p->next = NULL;

        now->next = p;
        now = p;
    }

    //让最后的节点指向头部，形成环形链表
    now->next = head;
    prev = now; // now在头部，那么now的前一个节点在尾部（环形）
    now = head;

    while((n--) > 1) //每次循环都会减少一个数字，最后一个节点就直接输出了
    {
        for(int i = 1; i < m; i++)
        {
            //从当前节点往前走
            prev = now;
            now = now->next;
        }
        cout<<now->data<<" ";
        //删除当前节点，直接跳过,prev的next指向now的后一个节点，这也是后面now要成为的节点
        prev->next = now->next;
        //先回收内存，避免跳过后指针改变

        delete now;
        now = prev->next;
    }

    cout<<now->data<<endl;
    delete now;


    return 0;
}
