#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto comp = [&nums](const int &idx1, const int &idx2 ) -> bool //按引用捕获nums
        {
            return nums[idx1] < nums[idx2];
        };
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);

        vector<int> max_nums;
        for(int i = 0; i < nums.size(); i++)
        {
            //除去对头的超过窗口值的元素
            while(!pq.empty() && pq.top() <= i - k ) pq.pop();
            pq.push(i);
            if(i >= k-1) //窗口形成, 记录最大值
            {
                max_nums.push_back(nums[pq.top()]);
            }
        }
        return max_nums;

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = sol.maxSlidingWindow(nums,3);
    for(auto num:res)
    {
        cout<<num<<'\n';
    }

    cout<<endl;
    return 0;
}