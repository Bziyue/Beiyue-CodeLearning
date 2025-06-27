#include<bits/stdc++.h>
using namespace std;
//定义链表-哈希表结构 实现快速查找和删除 map存储链表迭代器
list<int> arr;
unordered_map<int,list<int>::iterator> hash_arr;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N; cin>>N;
    //第一个同学入队
    arr.emplace_front(1);
    hash_arr[1] = arr.begin(); //生成迭代器

    for(int i = 2; i <= N; i++)
    {
        int idx,dir;cin>>idx>>dir;
        if(dir == 0)
        {
            //idx的左边插入，也就是插入到前面，直接使用 insert 即可
            hash_arr[i] = arr.insert(hash_arr[idx],i); //insert 返回插入后的新的元素的迭代器
        }
        else
        {
            //右边插入，那么idx的迭代器要往后移动1个位置
            hash_arr[i] = arr.insert(next(hash_arr[idx],1) , i); //在当前迭代器的后一个迭代器的前面插入元素
        }
    }

    int M;cin>>M;
    for(int i=1; i <= M; i++)
    {
        int idx;cin>>idx;
        if(hash_arr.find(idx) != hash_arr.end())
        {
            //存在，那么删除
            arr.erase(hash_arr[idx]);
            hash_arr.erase(idx);
        }
    }

    for(auto num:arr)
    {
        cout<<num<<" ";
    }

    return 0;
}