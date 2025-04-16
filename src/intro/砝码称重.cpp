#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    unordered_set<int> diffs = {0}; // 初始差为0

    for (int w : weights) {
        unordered_set<int> temp;
        for (int s : diffs) {
            temp.insert(s + w); // 放左边
            temp.insert(s - w); // 放右边
            temp.insert(s);     // 不放
        }
        diffs = temp; // 更新差值集合
    }

    // 统计所有非零绝对值的数目
    unordered_set<int> result;
    for (int s : diffs) {
        int abs_s = abs(s);
        if (abs_s != 0) {
            result.insert(abs_s);
        }
    }

    cout << result.size() << endl;
    return 0;
}