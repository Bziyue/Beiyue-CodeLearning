
namespace std{
    //特化哈希
    template<>
    struct hash<vector<int>>{
        size_t operator()(const vector<int>& vec)const
        {
            size_t seed = vec.size();
            for(auto i:vec)
            {
                seed ^= hash<int>()(i) + 0x9e3779b9 + (seed<<6) + (seed >> 2);
            }

            return seed;
        }
    };
}
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>,vector<string>> hashtable;
        //按照26个字母的出现次数定义哈希表
        for(auto str:strs)
        {
            vector<int> counts(26,0);
            for(auto ch:str)
            {
                ++counts[int(ch - 'a')];
            }

            hashtable[counts].emplace_back(str);
        }

        vector<vector<string>> results;
        for(auto result:hashtable)
        {
            results.emplace_back(result.second);
        }

        return results;
    }
};