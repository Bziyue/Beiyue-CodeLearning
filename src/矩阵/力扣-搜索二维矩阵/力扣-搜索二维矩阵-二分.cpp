#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mybinarysearch(vector<int> nums, int left, int right , int target)
    {
        
        while(left < right)
        {
            int mid = left + ((right - left)>>1);
            if(nums[mid] < target) 
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }

        }

        return left;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
    
        for(int row = 0; row < m; row++)
        {
            int res_idx = mybinarysearch(matrix[row],0,n,target);
            // auto it = lower_bound(matrix[row].begin(), matrix[row].end(),target);
            if(res_idx != n &&  matrix[row][res_idx] == target) return true;
            // if(it != matrix[row].end() && *it == target) return true;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution sol;
    sol.searchMatrix(matrix,5);

    return 0;
}