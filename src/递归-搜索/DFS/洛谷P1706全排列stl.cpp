#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        path.push_back(i);
    }

    do
    {
        for (auto num : path)
        {
            cout << setw(5) << num;
        }
        cout << '\n';

    } while (next_permutation(path.begin(), path.end()));

    return 0;
}