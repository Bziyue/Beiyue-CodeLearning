#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin>>t;
    queue<pair<int,int>> que;
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
            // que.push(make_pair(j,temp));
            que.emplace(j, temp);
            if(sum > maxsum)
            {
                maxsum = sum;
                start = p;
                end = j;
            }

            while (sum < 0 && !que.empty())
            {
                //使得sum小于0的子序列出队
                sum -= que.front().second;
                que.pop();
                if(que.empty())
                {
                    p = j+1; //队列为空指向下一个元素
                }
                else
                {
                    p = que.front().first;
                }
            }
            
        }
        cout<<"Case"<<" "<< i <<'\n';
        cout<< maxsum <<" "<< start <<" "<<end;
        cout<<endl;
    }

    return 0;
}