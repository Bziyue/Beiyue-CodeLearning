#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //思路：不断判断交换 下标 i 和 他对应的元素是否相等
        int n =nums.size();
        for(int i = 0; i < n; i++)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
            {//本来应该是判断 nums[i] 是否等于 i-1 也就是当前元素 和他的下标是否匹配 但是可能存在多个重复值
             //比如 1 号下标已经有 1 了 现在 五号下标又有一个1  交换后五号下标依然是1 那么会陷入无限循环的交换 
             // 所有判断方式改为 元素对应的下标 是否和元素相等 相当于就翻转了判断条件
             int j = nums[i] -1;
             swap(nums[i],nums[j]); //将元素交换到正确的下标
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1) //在 i 处 没有对应的 i+1元素
            {
                return i+1;
            }
        }

        return n+1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,0};

    cout<<sol.firstMissingPositive(nums)<<endl;

    return 0;
}