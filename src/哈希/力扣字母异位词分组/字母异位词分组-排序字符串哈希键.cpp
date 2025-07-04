class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //使用排序后字符串相等作为哈希的键
        unordered_map<string,vector<string>> hashtable;
        for(auto str:strs)
        {
            auto temp = str;
            sort(temp.begin(),temp.end());
            hashtable[temp].emplace_back(str);
        }

        vector<vector<string>> results;
        for(auto result:hashtable)
        {
            results.emplace_back(result.second);
        }

        return results;
    }
}; //push_back 27ms emplace_back 15ms