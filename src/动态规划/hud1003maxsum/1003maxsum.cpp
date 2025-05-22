#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t; cin>>t;
    for(int i =1; i <= t; i++)
    {
        int start = 1;
        int end =1;
        int position = 1;


        int n;cin >> n;
        for(int i = 1; i <= n; i++) cin >> dp[i];

        int maxsum = dp[1];
        for(int j = 2; j <= n; j++)
        {
            if(dp[j-1] + dp[j] >= dp[j])
            {
                dp[j] = dp[j-1] + dp[j];
            }
            else
            {
                position = j;
            }

            if(dp[j] > maxsum)
            {
                start = position;
                end = j;
                maxsum = dp[j];
            }

        }

        cout<<"Case"<<" "<< i <<'\n';
        cout<< maxsum <<" "<< start <<" "<<end<<"\n";
        if(i !=t) cout<<endl;
    }
}