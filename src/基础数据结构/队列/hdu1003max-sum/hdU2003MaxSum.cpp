#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin>>t;
    for(int i=1; i <= t;i++)
    {
        int maxsum = numeric_limits<int>::min();
        int sum = 0;
        int n; cin>>n;
        int start = 1;
        int end = 1;
        int p = 1; 
        for(int j = 1; j <= n; j++)
        {
            int temp; cin>>temp; sum+=temp;
            if(sum > maxsum )
            {
                maxsum = sum;
                start = p;
                end = j;
            }
            if(sum < 0)
            {
                p = j+1; 
                sum = 0;
            }
        }
        cout<<"Case"<<" "<< i <<'\n';
        cout<< maxsum <<" "<< start <<" "<<end;
        cout<<endl;
    }

    return 0;
}