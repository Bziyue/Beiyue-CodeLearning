#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& a,const vector<int> b) -> bool
        {
            return a[0] < b[0];
            //按照子数据区间头进行升序排列
        };
        sort(intervals.begin(), intervals.end(),comp);

        bool finished = false;

        while(!finished)
        {
            deque<vector<vector<int>>::iterator> need_merge;
            for(auto it = intervals.begin(); it < intervals.end(); it++)
            {   //找到所有需要合并的子区间
                if(it != intervals.begin())
                {
                    auto pre_it = it - 1;
                    if((*it).front() <= (*pre_it).back())//如果小于上一个区间的末尾
                    {
                        need_merge.push_back(it);
                    }
                }
            }

            if(need_merge.empty())
            {
                finished = true;
            }

            vector<vector<int>> new_intervals;
            for(auto it = intervals.begin(); it < intervals.end(); it++)
            {
                if(!need_merge.empty() && it == need_merge.front())
                {
                     //将当前数组的尾巴追加到上一个区间
                    if(new_intervals.back().back() < it->back()) //避免上一个区间 完全包含下一个区间的情况
                    {
                        new_intervals.back().back() = it->back();
                    }
                    need_merge.pop_front();
                }
                else
                {
                    new_intervals.push_back(*it);
                }
            }

            intervals = new_intervals;
        }

        return intervals;

    }
};

int main()
{
    Solution sol;
    std::vector<std::vector<int>> intervals = {
        {1, 3},
        {8, 10},
        {2, 6},
        {15, 18}
    };

    auto res = sol.merge(intervals);
    for(auto vec:res)
    {
        cout<<vec.front()<<" "<<vec.back()<<endl;
    }

    return 0;

}