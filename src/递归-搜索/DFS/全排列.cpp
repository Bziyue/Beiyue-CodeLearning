#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> Path;
vector<bool> used;

void dfs()
{
    //递归终止条件 ，达到数字长度要求
    if(Path.size() == n)
    {
        for(auto num : Path)
        {
            cout<<num<<" ";
        }
        cout<<endl;
        return; //结束分支
    }

    for(int i = 1; i <= n; i++)
    {
        if(!used[i]) //在当前路径中，i没有被使用
        {
            Path.push_back(i);
            used[i] = true;

            dfs();

            //回溯

            used[i] = false;
            Path.pop_back();
        }
    }
}

int main()
{
    cin>>n;
    used.resize(n+1,false);

    dfs();

    return 0;
}