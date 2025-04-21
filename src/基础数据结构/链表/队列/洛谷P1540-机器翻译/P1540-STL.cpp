#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int Hash[N] = {0};
queue<int> mem;
int main()
{
    int n , m; cin>>m>>n;
    int cnt = 0;
    while(n--)
    {
        int word; cin >> word;
        if(Hash[word]) continue; //如果已经在内存，不进行操作
        else
        {
            //检查是否已满
            if(int(mem.size()) == m)
            {
                Hash[mem.front()] = 0; //出队
                mem.pop();
            }

            //进行查询并入队
            mem.push(word);
            cnt++;
            Hash[word] = 1;
        }

    }

    cout<<cnt<<endl;
    return 0;
}