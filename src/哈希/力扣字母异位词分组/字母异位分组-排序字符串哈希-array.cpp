namespace std{
    template<typename T, size_t N>
    struct hash<array<T,N>>
    {
        size_t operator()(const array<T,N>& arr)const
        {
            size_t seed = N;
            for(auto i : arr)
            {
                seed ^= hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }

            return seed;
        }
    };
}


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int,26>,vector<string>> hashtable;
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