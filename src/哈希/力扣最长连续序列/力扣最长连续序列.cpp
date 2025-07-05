class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(auto num:nums) nums_set.insert(num);

        //遍历set,如果x-1不存在 寻找x+1 (x可通过x-1遍历)
        int current_num = 0;
        int current_length = 0;
        int maxlength = 0;
        for(auto num:nums_set)
        {
            current_num = num;
            if(nums_set.count(current_num - 1) == 0) //不存在x-1
            {
                current_length = 1;
                while(nums_set.count(current_num+1) == 1)
                {
                    ++current_length;
                    ++current_num;
                }
                maxlength = max(current_length,maxlength);
            }
        }

        return maxlength;
    }
};