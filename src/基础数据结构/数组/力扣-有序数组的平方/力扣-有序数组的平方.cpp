
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int idx = n-1,left=0 , right=n-1; left < right; idx--) res[idx] = (abs(nums[left]) <= abs(nums[right]) ? (right--,nums[right+1]*nums[right+1]) : (left++,nums[left-1]*nums[left-1]));
        return res;
    }

    
};

int main()
{
    Solution sol;
    vector<int> vec = {-5,-2,0,2,3,5,6};
    auto res = sol.sortedSquares(vec);
    for(auto num:res)
    {
        cout<<num<<" ";
    }

    cout<<endl;

    return 0;
}