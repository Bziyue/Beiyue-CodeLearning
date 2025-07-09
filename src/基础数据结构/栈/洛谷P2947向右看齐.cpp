#include <bits/stdc++.h>
using namespace std;
const int num = 1e5 + 3;
int arr[num];
int ans[num];
stack<int> st;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++)
    {
        // 从后往前遍历数组

        while (!st.empty() && arr[st.top()] <= arr[N - i])
            st.pop(); // 栈顶必须严格小于当前奶牛高度
        if (!st.empty())
            ans[N - i] = st.top() + 1;
        else
            ans[N - i] = 0;

        st.push(N - i);
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << '\n';

    return 0;
}