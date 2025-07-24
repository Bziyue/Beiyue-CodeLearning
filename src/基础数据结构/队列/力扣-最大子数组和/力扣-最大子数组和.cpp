class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = numeric_limits<int>::min();
        int left = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            max_sum = max(sum,max_sum);
            //贪心法求解
            sum = (sum < 0 ? 0 : sum);
        }

        return max_sum;
    }
};