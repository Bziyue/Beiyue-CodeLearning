#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> cnt({sum,1});
        //由于不显示生成前缀和，那么对于第一个 和 为0的元素特殊处理
        int ans = 0;

        for(auto num:nums)
        {
            sum += num;
            ans += cnt.contains(sum - k) ? cnt[sum-k] :  0;
            cnt[sum]++;
        }

        return ans;
    }
};