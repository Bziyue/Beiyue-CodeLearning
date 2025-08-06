#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //利用矩阵的升序性质 逐行逐列排除
        int row = 0;
        int col = n-1;
        while(row < m && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col] < target) //右上角元素小于目标值 意味着整行的元素都不会大于目标值 行向下扫描
            {
                row++;
            }
            else if(matrix[row][col] > target) //右上角元素大于目标值 意味着这列的元素往下肯定也大于目标值 排除该列
            {
                col--;
            }
        }

        return false;
    }
};