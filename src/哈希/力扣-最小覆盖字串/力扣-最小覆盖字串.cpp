#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isCovered(int ch_of_t[], const vector<int>& ch_idx_of_t, int ch_of_s[])
    {
        for(auto& idx : ch_idx_of_t)
        {
            if(ch_of_s[idx] < ch_of_t[idx])
            {
                return false;
            }
        }

        return true;
    }
    string minWindow(string s, string t) {
        //使用一个数组记录t中每个字母出现的次数
        int ch_of_t[128]{};
        int ch_of_s[128]{};
        for(auto ch:t)
        {
            ch_of_t[ch]++;
        }

        vector<int> ch_idx_of_t;
        for(int i = 0; i < 128;i++)
        {
            if(ch_of_t[i] > 0) ch_idx_of_t.push_back(i); //记录 t 中出现过的字母
        }

        int ansLeft = -1;
        int ansRight = s.size();

        for(int left = 0,right=0; right < s.size(); right++)
        {
            ch_of_s[s[right]]++;
            while(isCovered(ch_of_t,ch_idx_of_t,ch_of_s))
            {
                if(right - left < ansRight - ansLeft)
                {
                    ansLeft = left;
                    ansRight = right;
                }

                //尝试移除左边元素
                ch_of_s[s[left]]--;
                left++;
            }
        }

        return ansLeft >= 0 ? s.substr(ansLeft,ansRight - ansLeft + 1) :""; //返回从left开始 长度为left到right的字符串

    }
};

int main()
{
    Solution sol;
    string s = "a";
    string t = "a";

    auto res = sol.minWindow(s,t);
    cout<<res<<endl;

    return 0;
}