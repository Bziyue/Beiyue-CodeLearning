
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
                        // 初始化捕获                              显式声明返回类型
        auto arrayHash = [fn = hash<int>{}] (const array<int,26>& arr) -> size_t{
            
            size_t seed = arr.size();
            for(auto i : arr)
            {
                seed ^= fn(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }

            return seed;
        };

        unordered_map<array<int,26>,vector<string>,decltype(arrayHash)> hashtable(0,arrayHash);
        for(auto str:strs)
        {
            array<int,26> counts{};
            for(auto ch : str)
            {
                ++counts[ch - 'a'];
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