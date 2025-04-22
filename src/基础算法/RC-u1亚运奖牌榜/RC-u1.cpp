#include<bits/stdc++.h>
using namespace std;
struct country{
    int scores[4] = {};
};
country countrys[2];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    while(n--)
    {
        int c,score;cin>>c>>score;
        countrys[c].scores[score] += 1;
    }
    bool first_win = true;
    if((countrys[0].scores[1] < countrys[1].scores[1]) || 
       (countrys[0].scores[1] == countrys[1].scores[1] && countrys[0].scores[2] < countrys[1].scores[2]) || 
       (countrys[0].scores[1] == countrys[1].scores[1] && countrys[0].scores[2] == countrys[1].scores[2] && countrys[0].scores[3] < countrys[1].scores[3]))
    {
        first_win = false;
    }

    string s1 = "The first win!";
    string s2 = "The second win!";
    cout<<countrys[0].scores[1]<<" "<<countrys[0].scores[2]<<" "<<countrys[0].scores[3]<<'\n';
    cout<<countrys[1].scores[1]<<" "<<countrys[1].scores[2]<<" "<<countrys[1].scores[3]<<'\n';
    cout<<(first_win ? s1 : s2)<<endl;
    
}
