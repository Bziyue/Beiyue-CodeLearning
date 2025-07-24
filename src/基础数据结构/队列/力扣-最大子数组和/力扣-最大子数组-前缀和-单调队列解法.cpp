#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //构造前缀和
        vector<int> prefix(nums.size() + 1,0);
        for(int i = 1; i <= nums.size(); i++)
        {
            prefix[i] = nums[i-1] + prefix[i-1]; //对于nums进行下标偏移 
        }

        int max_sum = numeric_limits<int>::min();
        int sum = 0;

        //那么问题转换为 寻找 right 和 left 使得 prefix[right] - prefix[left] 最大 
        // 那么遍历一遍前缀和 维护寻找得到最小left

        for(int right = 1,min_left = 0; right <= nums.size(); right++)
        {
            max_sum = max(max_sum, prefix[right] - prefix[min_left]);
            min_left = (prefix[right] < prefix[min_left] ? right : min_left);
        }

        return max_sum;
    }
};