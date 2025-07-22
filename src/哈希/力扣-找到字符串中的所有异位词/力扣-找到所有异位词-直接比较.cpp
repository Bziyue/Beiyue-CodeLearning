#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto length_s = s.size();
        auto length_p = p.size();

        if(length_s < length_p) return {};
        vector<int> count_window(26,0);
        vector<int> count_p(26,0);

        //统计p和初始窗口的字符分布
        for(size_t i = 0; i < length_p; i++)
        {
            count_window[size_t(s[i] - 'a')]++;
            count_p[size_t(p[i] - 'a')]++;
        }

        vector<int> result;
        if(count_window == count_p)
        {
            result.push_back(0);
        }

        for(size_t i = 0; i < length_s - length_p; i++)
        {
            --count_window[size_t(s[i]) - 'a'];
            ++count_window[size_t(s[i + length_p]) - 'a'];

            if(count_window == count_p)
            {
                result.push_back(i+1);
            }
        }

        return result;

    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    Solution sol;
    auto result = sol.findAnagrams(s,p);

    for(auto i:result)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}