class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
        return a[0] < b[0];
    }); //对区间按照左端点排序

    vector<vector<int>> merged;
    merged.reserve(intervals.size());

    for(int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];

            if(!merged.size() || left > merged.back()[1])
            {
                merged.push_back({left,right});
            }
            else
            {
                merged.back()[1] = max(right,merged.back()[1]);
            }
        }

    return merged;

}
};