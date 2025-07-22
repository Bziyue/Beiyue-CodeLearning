#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size()+1,0);

        for(int i = 0; i < nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }

        // unordered_map<int,int> cnt({0,1});
        unordered_map<int,int> cnt; //无需处理0 因为遍历从0开始 
        int ans = 0;
        for(auto s_j : prefix)
        {
            ans += cnt.contains(s_j - k) ? cnt[s_j-k] : 0;
            cnt[s_j]++;
        }

        return ans;
    }
};