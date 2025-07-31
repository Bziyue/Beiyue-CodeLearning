#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //思路：缺失的正数一定出现在【1，N+1】之间，其中N+1是数组的长度
        //那么可以通过遍历【1，N】之间的元素判断 是否存在于nums中
        //这里可以通过哈希表快速完成判断
        //实际实现时，并不需要建立一个哈希表 可以利用原数组的下标关系 进行隐形遍历
        // 巧妙地利用数组本身的索引来充当哈希表的键（Key），用对应位置上数值的正负号来充当哈希表的值（Value），以标记某个数字是否存在。
        int n = nums.size();
        //第一次遍历 将所有负数全部变成N+1 避免干扰判断
        for_each(nums.begin(),nums.end(),[&](int& num){
            if(num <= 0) num = n+1; //设置为numeric_limits<int>::max() 也可以 但不能是其他数 避免出现在原本数组范围内
        });

        //利用原数组的隐式下标关系 将出现过的元素标记为负
        for(int i = 0; i < n; i++)
        {
            int num = abs(nums[i]); //重新获得原数值进行判断
            if(num <= n)
            {
                nums[num-1] = -abs(nums[num-1]); //将对应下标的元素设置为负数 去abs而不是直接变为负 是为了避免可能出现的多次操作
            }
        }


        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) return i+1;
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