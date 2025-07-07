class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,numeric_limits<int>::max())); 
        //初始化为最大，避免特殊处理边界
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(i==0 && j==0) dp[i+1][j+1] = grid[i][j]; //初始化1 1，特殊处理
                else dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];//相当于最外层包了一层 max
            }
        }

        return dp[grid.size()][grid[0].size()];
    }
};