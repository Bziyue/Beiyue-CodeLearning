class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre_max(n,0);
        vector<int> suf_max(n,0);

        //建立前向高度和后向高度
        pre_max[0] = height[0];
        suf_max[n-1] = height[n-1];

        for(int i = 1; i < n; i++)
        {
            pre_max[i] = max(pre_max[i-1],height[i]); //当前位置的最大高度等于 前面的最大高度和当前高度取max
            suf_max[n-(i+1)]=max(suf_max[n-(i+1) + 1], height[n-(i+1)]); //从后往前遍历高度数组 n-i代表倒数第i个位置 
                                                                        //-1位置已经赋值，所以要从-2位置开始    
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += min(pre_max[i],suf_max[i]) - height[i];
        }

        return ans;
    }
};