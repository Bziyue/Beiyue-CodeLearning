#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool is_equal(string str, unordered_map<char,int> str2)
    {
        bool result = true;
        for(auto ch : str)
        {
            auto it = str2.find(ch);
            if(it == str2.end()) //字母不匹配
            {
                result = false;
                return result;
            }
            else
            {
                //找到了 但计数为0 也返回,代表只是和相同，但是字母数不同
                if(str2[ch] == 0)
                {
                    result = false;
                    return result;
                }
                else
                {
                    --str2[ch]; //计数减一
                }
            }
        }

        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // if(strs.size() <= 1) return vector<vector<string>>{strs}; 

        //构造三重哈希表 以str的字符数字相加的和 作为键 存储和相同的字符串
        //第二个哈希表以下标作为值，用于存储和访问
        //第三个哈希表以字母和计数作为键值对 用于快速判断两个字符串是否为字符异位 
        

        unordered_map<int,unordered_map<int,unordered_map<char,int>>> dul_hashtable;
        vector<int> sums;
        sums.resize(strs.size()); //记录个各字符串的字母和

        for(int i = 0; i < strs.size(); i++)
        {
            unordered_map<char,int> temp;
            int sum = 0;
            auto str = strs[i];

            for(auto ch:str)
            {
                sum += int(ch);

                auto it = temp.find(ch); //为每一个字母设置计数
                if(it != temp.end())
                {
                    ++temp[ch];
                }
                else
                {
                    temp[ch] = 1;
                }   
            }

            dul_hashtable[sum][i] = temp;
            sums[i] = sum; //记录每个字符串的字母和

        }

        //遍历原数组，寻找字母和相同的其他字符串
        vector<vector<string>> results;
        for(int i = 0; i < strs.size(); i++)
        {
            //取出字母和相同的字符串,已经被使用的就跳过
            if(sums[i] != -1)
            {
                auto& equal_sum_strs = dul_hashtable[sums[i]]; //取出字母和相同的字符串
                vector<string> result;
                //判断这些是否和str[i]为异位字符串 肯定和自己相同，所以可以加入自己
                for(auto it = equal_sum_strs.begin(); it != equal_sum_strs.end(); ++it)
                {
                    if(is_equal(strs[i], it->second))
                    {
                        result.push_back(strs[it->first]);
                        sums[it->first] = -1; //标记为使用
                    }
                }

                results.push_back(result);
            }

        }

        return results;
    }
};


int main()
{
    Solution sol;
    vector<string> test1{"",""};
    auto res = sol.groupAnagrams(test1);

    for(auto ss:res)
    {
        for(auto s:ss)
        {
            cout<<s<<endl;
        }
    }

    return 0;
}