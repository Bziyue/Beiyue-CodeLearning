#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>grid, int x,int y)
{
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    //边界处理
    dp[0][0] = grid[0][0];

    for(int j = 1 ; j < grid.size(); j++)
    {
        //处理第一行
        dp[0][j]  = grid[0][j] + dp[0][j-1];  
    }

        for(int i = 1 ; i < grid.size(); i++)
    {
        //处理第一列
        dp[i][0]  = grid[i][0] + dp[i-1][0];  
    }

    //填充dp矩阵
    for(int i = 1; i < grid.size(); i++)
    {
        for(int j = 1; j < grid[0].size(); j++)
        {
            //当前状态要么从左边过来 要吗从上面下来
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }


    return dp[x][y];
}

int main() {
    // 示例输入
    std::vector<std::vector<int>> grid = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    int target_x = 2;
    int target_y = 2;

    // 计算最小成本
    int result = minPathSum(grid, target_x, target_y);

    // 输出结果
    std::cout << "输入:" << std::endl;
    std::cout << "grid = [" << std::endl;
    for(const auto& row : grid) {
        std::cout << "  [";
        for(size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i] << (i == row.size() - 1 ? "" : ",");
        }
        std::cout << "]," << std::endl;
    }
    std::cout << "];" << std::endl;
    std::cout << "x = " << target_x << ", y = " << target_y << std::endl;
    std::cout << std::endl;
    std::cout << "输出: " << result << std::endl;

    return 0;
}