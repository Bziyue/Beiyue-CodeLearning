#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k %= nums.size(); //避免多转好几圈

         while(k-- > 0)
         {
            int prenum = nums[0];
            for(int i = 0; i <nums.size(); i++)
            {
                int temp = nums[(i+1)%nums.size()]; //避免被覆盖
                nums[(i+1)%nums.size()] = prenum;
                prenum = temp;
            }
         }
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