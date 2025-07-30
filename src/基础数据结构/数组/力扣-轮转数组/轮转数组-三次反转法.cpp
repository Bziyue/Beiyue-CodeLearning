#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k %= nums.size(); //避免多转好几圈

         //手写reverse
         auto my_reverse = [&](int i,int j)
         {
            while(i < j)
            {
                swap(nums[i++],nums[j--]);
            }
         };
        //  reverse(nums.begin(),nums.end());
        //  reverse(nums.begin(),nums.begin()+k);
        //  reverse(nums.begin()+k,nums.end());
         my_reverse(0,nums.size()-1);
         my_reverse(0,k-1);
         my_reverse(k,nums.size()-1);

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    sol.rotate(nums,21+3);

    for(auto num:nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}