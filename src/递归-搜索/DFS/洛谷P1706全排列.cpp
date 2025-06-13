#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;
vector<bool> used;

void dfs()
{
    if(int(path.size()) == n)
    {
        for(auto num : path)
        {
            cout<<setw(5)<<num;
        }

        cout<<'\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            path.push_back(i);
            used[i] = true;

            dfs();

            //回溯

            used[i] = false;
            path.pop_back();

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