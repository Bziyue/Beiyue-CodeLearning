class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target-nums[i]);

            if(it != hashtable.end())
            {
                return {i, hashtable[target-nums[i]]};
            }

            hashtable[nums[i]] = i;
        }

        return {};
    }
};