#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int total_num = m*n;
        vector<int> res;
        res.reserve(total_num);
        int l_r_limits = 0;
        while(res.size() < total_num)
        {
            //使用四个for循环完成 避免繁琐的状态转移判断
            //每完成一圈 边界往内收缩一圈
            for(int j = l_r_limits; j < n;j++) //上沿
            {
                res.push_back(matrix[l_r_limits][j]);
            }
            if(res.size() == total_num) break;

            for(int i = l_r_limits+1; i < m;i++) //右沿
            {
                res.push_back(matrix[i][n-1]);
            }
            if(res.size() == total_num) break; 

            for(int j = n-2; j >= l_r_limits; j--)//下沿
            {
                res.push_back(matrix[m-1][j]);
            }
            if(res.size() == total_num) break;

            for(int i = m-2; i >= l_r_limits+1; i--)//左沿
            {
                res.push_back(matrix[i][l_r_limits]);
            }
            if(res.size() == total_num) break;

            l_r_limits++;
            m--;
            n--;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9} };

    auto res = sol.spiralOrder(matrix);

    for(auto num:res)
    {
        cout<<num<<' ';
    }

    cout<<endl;

    return 0;
}