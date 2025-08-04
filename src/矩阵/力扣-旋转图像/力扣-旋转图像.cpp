#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //思路 位于(i,j)位置的元素旋转后 位于(j, n-i-1)
        //一圈 一圈的旋转 从一个位置开始 交换四次之后重新回到该位置 遍历下一个位置
        int n = matrix.size();
        int circle = 0;
        int total_circle = (n+1) / 2; //一个矩阵最多有 ⌈n/2⌉ 圈

        while(circle < total_circle)
        {
            int row = circle;
            for(int col = circle; col < ((n-1)-circle); col++) //最多遍历一行的前n-1个元素
            {//对于偶数n,那么是最内圈的第一个元素 奇数n,最内圈的唯一一个元素不交换
                int current_num = matrix[row][col];
                int current_row = row;
                int currrent_col = col;
                for(int i = 0; i <= 3; i++)
                {
                    int next_row = currrent_col;
                    int next_col = n - current_row - 1;
                    swap(current_num,matrix[next_row][next_col]);

                    current_row = next_row;
                    currrent_col = next_col;
                }
            }
            circle++;
        }
    }
};