#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;
const int N = 1e6 + 10;

int main()
{
    ull n; cin>>n;
    ull dp[3];
    dp[0] = 0;
    dp[1] = 1;

    if( n == 1) 
    {
        cout<<dp[1]<<endl;
        return 0;
    }


    while(n--)
    {
        dp[2] = dp[1] + dp[0];

        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    cout<<dp[2]<<endl;
    return 0;
}