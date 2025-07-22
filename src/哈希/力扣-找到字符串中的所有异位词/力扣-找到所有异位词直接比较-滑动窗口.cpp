#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto length_s = s.size();
        auto length_p = p.size();


        vector<int> count_window(26,0);
        vector<int> count_p(26,0);
        vector<int> result;

        for(auto ch:p)
        {
            count_p[size_t(ch-'a')]++;
        }

        for(size_t right = 0, left = 0; right < length_s ; right++)
        {
            count_window[size_t(s[right] - 'a')]++;
            if(right - left +1 == length_p)
            {
                if(count_window == count_p)
                {
                    result.push_back(left);
                }
                count_window[size_t(s[left] - 'a')]--;
                left++;
            }
        }

        return result;

    }
};

int main()
{
    string s = "cbacbabacd";
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