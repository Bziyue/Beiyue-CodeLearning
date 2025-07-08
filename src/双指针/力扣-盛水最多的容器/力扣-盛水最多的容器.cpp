class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;  // 添加空检查
        int fast,slow;
        for(fast = 0,slow=0; fast < nums.size(); ++fast)
        {
            if(nums[fast] != 0) 
            {
                swap(nums[fast],nums[slow]);
                ++slow;
            }

        }
    }
};