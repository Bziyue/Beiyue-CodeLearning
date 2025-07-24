#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //思路：很明显当前位置 i 记录的是以 i 为结尾的连续子数组最大和
        // dp[i] = max(dp[i-1]+nums[i], nums[i]) 返回最大的dp[i] 即可
        // 由于dp[i] 只依赖于上一个dp[i-1] 所以只需要存储一个pre即可
        int pre = 0;
        int max_sum = nums[0];

        for(const auto &num:nums)
        {
            pre = max(pre+num, num);
            max_sum = max(pre,max_sum);
        }

        return max_sum;
    }
};