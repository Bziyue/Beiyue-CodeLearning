#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        //正向乘一遍 得到1 a0 a0a1 a0a1a2 ... a0a1a2a3...an-1
        int n = nums.size();
        for(int i = 1; i< n; i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        //反向乘一遍 得到a1a2a3a4...an a2a3a4...an ... an 1
        int temp = 1;
        for(int i=2; i <= n; i++)
        {
            temp *= nums[n-i+1];
            ans[n-i] *=  temp;
        }
        return ans;
    }

    
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    auto ans = sol.productExceptSelf(nums);

    for(auto& num:ans)
    {
        cout<<num<<" ";
    }

    cout<<endl;
}