#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    struct Statue
    {
        int iSum, lSum,rSum,mSum;
    };
    
    Statue pushUP(Statue l, Statue r)
    {
        int iSum = l.iSum + r.iSum; // 新的大区间的和 等于左右之和
        int lSum = max(l.lSum,l.iSum + r.lSum);//新的靠左区间和 要么等于原来的小的左区间和 要么等于左小区间加上右小区间的左区间
        int rSum = max(r.rSum,r.iSum + l.rSum);//同理：靠右区间最大和 要么等于原来右区间的右区间和 要么等于整个右区间和 加上左小区间的右区间
        int mSum = max(max(l.mSum,r.mSum),l.rSum + r.lSum); //要么等于左 右区间的最大和 或者在中间 左区间的右和 加上 有区间的左和

        return (Statue) {iSum, lSum, rSum, mSum};
    }
    Statue get(const vector<int>& arr, int l, int r)
    {
        if(l == r)
        {
            return (Statue) {arr[l], arr[l], arr[l], arr[l]};
        }

        int m = l + (r - l)/2;
        Statue left_sub = get(arr, l,m);
        Statue right_sub = get(arr,m+1,r);
        return pushUP(left_sub,right_sub);
    }
    int maxSubArray(vector<int>& nums) {

       
        return get(nums,0,nums.size()-1).mSum;
    }
};