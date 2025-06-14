#include <bits/stdc++.h>
using namespace std;

struct State
{
    int x, y;

    int step;
};

vector<vector<int>> mymap;
vector<vector<bool>> visited;
queue<State> q;
int n, m;
// 方向数组 上下左右

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(int start_x, int start_y, int end_x, int end_y)
{
    visited.assign(n, vector<bool>(m, false)); // 重新初始化vector

    // 起点入队
    q.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;

    while (!q.empty()) // 邻居入队 一直到起点为空
    {
        State current = q.front();
        q.pop();

        // 判断是否为终点
        if (current.x == end_x && current.y == end_y)
        {
            return current.step;
        }

        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int next_x = current.x + dx[i];
            int next_y = current.y + dy[i];

            // 判断邻居是否合法 如果合法那么邻居入队
            if (next_x >= 0 && next_x < n && // 在边界内
                next_y >= 0 && next_y < m &&
                mymap[next_x][next_y] == 0 &&     // 不是障碍物
                visited[next_x][next_y] == false) // 没有访问过
            {
                visited[next_x][next_y] = true;
                q.push({next_x, next_y, current.step + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    mymap = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}};
    n = 3;
    m = 4;
    int result = bfs(0, 0, 2, 3);

    if (result == -1)
    {
        cout << "无解" << endl;
    }
    else
    {
        cout << "最短路径需要 " << result << " 步。" << endl;
    }

    return 0;
}
