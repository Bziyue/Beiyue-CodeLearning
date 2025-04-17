#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long ;
bool isSpecial(ull num)
{
    ull temp;
    while(num) //依次取出数的各个位数
    {
        temp = num % 10; 
        if(temp == 2 || temp == 0 || temp == 1 || temp == 9) return true;

        num /= 10;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ull n;cin>>n;
    ull sum = 0;
    for(ull i = 1;i <= n;i++)
    {
        if(isSpecial(i)) sum += i;
    }
    cout<<sum<<endl;
    
    return 0;
}