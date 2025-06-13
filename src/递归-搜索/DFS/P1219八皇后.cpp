#include <bits/stdc++.h>
using namespace std;

vector<int> used_col;
vector<int> used_diag;
vector<int> used_diag2;
vector<int> path;
int Count;
int n;

void dfs(int row)
{
        if(row == n+1)
        {
            Count++;
            if(Count <= 3)
            {
                for(auto num:path) cout<<num<<" ";
                cout<<'\n';
            }//输出前三个解

            return;
        }

        //遍历每一列
        for(int col = 1; col <= n; col++)
        {
            //列未使用               主对角线未使用 加上偏移量n  副对角线没有用
            if(!used_col[col] && !used_diag[row-col + n-1] && !used_diag2[row+col])
            {
                path.push_back(col);
                used_col[col] = 1;
                used_diag[row-col + n-1] = 1;
                used_diag2[row+col] = 1;

                dfs(row+1);

                //回溯
                path.pop_back();
                used_col[col] = 0;
                used_diag[row-col + n-1] = 0;
                used_diag2[row+col] = 0;
            }
        }
  
}
int main()
{
    cin>>n;
    used_col.resize(n+1,0);
    used_diag.resize(2*n+2,0);
    used_diag2.resize(2*n+2,0);

    dfs(1);

    cout<<Count;

    return 0;
}