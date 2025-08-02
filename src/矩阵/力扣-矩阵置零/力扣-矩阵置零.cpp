#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRowhasZero = false;
        bool firstColhasZero = false;

        // 扫描矩阵 把存在0的行列第一个元素置为0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0 && matrix[i][j] == 0) //第一行
                    {
                        firstRowhasZero = true;
                    }
                    if (j == 0 && matrix[i][j] == 0) //第一列
                    {
                        firstColhasZero = true;
                    }

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) // 避免破坏第一行第一列的标记
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 特殊处理第一行 第一列

        if (firstRowhasZero)
        {
            fill(matrix[0].begin(), matrix[0].end(), 0); // 第一行全部为0
        }
        if (firstColhasZero)
        {
            for (int i = 1; i < n; i++)
            {
                matrix[i][0] = 0; // 第一列全部为0
            }
        }
    }
};