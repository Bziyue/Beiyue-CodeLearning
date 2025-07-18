#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //自定义哈希函数 通过26个字母的出现次数快速判断是否相等
    size_t hash_of_vec(const vector<int> &vec)
    {
        size_t seed = vec.size();
        for(auto num:vec)
        {
            seed ^= hash<int>()(num) + 0x9e3779b9 + (seed<<6) + (seed >> 2);
        }

        return seed;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> vec_p(26,0);
        for(auto ch:p)
        {
            vec_p[int(ch- 'a') ]++;
        }

        auto hash_of_p = hash_of_vec(vec_p);

        vector<int> vec_sub(26,0);
        vector<int> result;
        auto num_s = s.size();
        auto num_p = p.size();
        
        for(int left = 0,right = 0; right < num_s; right++)
        {
            //统计当前字串的字符分布
            vec_sub[int(s[right] - 'a')]++;
            auto hash_of_sub = hash_of_vec(vec_sub);

            if(right - left + 1 == num_p)
            {
                if(hash_of_sub == hash_of_p)
                {
                    result.push_back(left);
                }
                vec_sub[int(s[left] - 'a')]--;
                left++;
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