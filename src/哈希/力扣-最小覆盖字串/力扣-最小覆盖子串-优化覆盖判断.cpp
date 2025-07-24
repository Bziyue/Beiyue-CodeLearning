#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> cnt;
        int less = 0; //记录当前字串中有多少种字符的个数小于t
        //cnt 也可以使用哈希表实现
        for(auto ch : t)
        {
            //统计字符种类
            if(!cnt.contains(ch)) //没有出现过的字符
            {
                less++;
            }
            cnt[ch]++; //统计每种字符的出现次数
        }

        //字串和t都利用同一块 cnt 当cnt[ch]==0时代表满足了最小覆盖
        int ansLeft = -1;
        int ansRight = s.size();

        for(int left=0,right=0; right < s.size(); right++)
        {
            auto ch = s[right];
            cnt[ch]--; //如果是t内不存在的字符，那么cnt[ch] < 0，不影响后面的判断

            if(cnt[ch] == 0) //代表出现了一次字串中的某个字符个数大于cnt中的某个字符 
            {
                less--; //即使后续出现更多的这个字符也不影响
            }

            while(less == 0) //是一个覆盖
            {
                //更新答案
                if(right - left < ansRight - ansLeft)
                {
                    ansRight = right;
                    ansLeft = left;
                }
                //尝试缩短左端点
                char ch_of_substr = s[left];
                if(cnt[ch_of_substr] == 0) //如果 == 0 那么代表当前字串中的该字符个数刚好等于t中的字符个数
                {                                       //如果进行了移除，那么就会使得该字符无法覆盖 所有less++
                    less++;                         //t中没有的字符 不会出现在该分支 因为为负  
                }                                        //t中没有的字符的cnt 加到0之后 代表字串中没有该字符了 left不会索引到这个字符

                cnt[ch_of_substr]++; //
                left++;
            }
        }


        return ansLeft == -1 ? "" : s.substr(ansLeft,ansRight - ansLeft + 1);
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