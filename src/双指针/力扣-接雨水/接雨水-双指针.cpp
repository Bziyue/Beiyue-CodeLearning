class Solution {
public:
    int trap(vector<int>& height) {
        int left,right;
        left = 0;
        right = height.size() - 1;

        int left_max = height[left];
        int right_max = height[right];

        int ans = 0;
        //双指针向内遍历，每次对最小的边进行计算，因为接水量取决于二者之中的小值
        while(left <= right) //需要遍历到每一个单位
        {
            left_max = max(left_max,height[left]);
            right_max = max(right_max,height[right]);

            if(left_max <= right_max) //
            {
                ans += left_max - height[left];
                left++;
            }
            else
            {
                ans += right_max - height[right];
                right--;
            }
        }

        return ans;
    }
};