#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = numeric_limits<int>::min();
        int sum = 0;

        queue<int> que;

        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            que.push(nums[right]);
            max_sum = max(sum,max_sum);
            while(sum < 0 && !que.empty())
            {
                sum -= que.front();
                que.pop();
            }
        }

        return max_sum;
    }
};