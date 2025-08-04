#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //旋转左上块 对于行：n/2 对于列(n+1)/2
        int n = matrix.size();
        for(int row = 0; row < n/2; row++)
        {
            for(int col = 0; col < (n+1)/2; col++)
            {
                int temp = matrix[row][col]; //左上角元素
                //思路 位于(i,j)位置的元素旋转后 位于(j, n-i-1)
                //（i,j）-> (j, n-i-1) 左上角
                // (j, n-i-1) -> (n-i-1,n-j-1) 右上角
                // (n-i-1,n-j-1) -> (n-j-1,i) 右下角
                // (n-j-1,i) -> (i,j) 左下角
                matrix[row][col] = matrix[n-col-1][row];
                matrix[n-col-1][row] = matrix[n-row-1][n-col-1];
                matrix[n-row-1][n-col-1] = matrix[col][n-row-1];
                matrix[col][n-row-1] = temp;
            }
        }
    }
};