#include <bits/stdc++.h>
using namespace std;
const int max_n = 405;
const int max_m = 405;
int n,m;

vector<vector<int>> dist(max_n,vector<int>(max_m,-1)); //二维全局距离数组
struct position{
    int x,y;
    position(int x,int y) : x(x),y(y){};
};
queue<position> q;

int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};

void bfs(int x,int y)
{
    //起始位置入队
    dist[x][y] = 0;
    q.emplace(x,y); //在使用emplace构造对象时，如果是自定义对象需要手动写一个构造函数，对应参数列表
                            //如果容器内部是pair，那么直接传入参数

    while(!q.empty())
    {
        position current_pos = q.front();
        q.pop(); //取出对头

        //遍历对头的八个方向入队
        for(int i = 0; i < 8 ; i++)
        {
            int next_x = current_pos.x + dx[i];
            int next_y = current_pos.y + dy[i];

            //判断合法性 首先判断是否在范围内 再判断是否访问过
            if(next_x >= 1 && next_x <= n && 
               next_y >= 1 && next_y <= m &&
               dist[next_x][next_y] == -1) //代表没有访问过
               {
                    dist[next_x][next_y] = dist[current_pos.x][current_pos.y] + 1;
                    q.emplace(next_x,next_y);
               }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;

    int x,y;cin>>x>>y;

    bfs(x,y);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m ; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;

}