#include <bits/stdc++.h>
using ull = unsigned long long;
using namespace std;
const int N = 1e6 + 10;
ull dp[N];
ull fib(ull n)
{
    if (n == 0) 
    {
        dp[0] = 0;
        return dp[0];
    }
    if (n == 1)
    {
        dp[1] = 1;
        return dp[1];
    }

    if( dp[n] != 0 ) return dp[n];
    else
    {
        dp[n] = fib(n - 1) + fib( n - 2);
        return dp[n];
    }
}

int main()
{
    ull n; cin>>n;
    cout << fib(n) <<endl;
    return 0;
}