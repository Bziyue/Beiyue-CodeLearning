#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
int n;
char word_matrix[MAX_N][MAX_N];
char mask_matrix[MAX_N][MAX_N];
bool is_yizhong;
const string yizhong = "yizhong";

#define belong_yizhong 1
#define not_yizhong 2
#define MaxDep 7

bool is_vaild(char &letter)
{
    if (letter == 'y' ||
        letter == 'i' ||
        letter == 'z' ||
        letter == 'h' ||
        letter == 'o' ||
        letter == 'n' ||
        letter == 'g')
    {
        return true;
    }
    else
        return false;
}

void dfs1(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第一个方向
        dfs1(row - 1, col - 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs2(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第2个方向
        dfs2(row - 1, col, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs3(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第3个方向
        dfs3(row - 1, col + 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs4(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第4个方向
        dfs4(row, col - 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs5(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第5个方向
        dfs5(row, col + 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs6(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第6个方向
        dfs6(row + 1, col - 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs7(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第7个方向
        dfs7(row + 1, col, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
void dfs8(int row, int col, int dep)
{
    if (row < 1 || col < 1 || row > n || col > n)
    {
        // 超出矩阵范围
        is_yizhong = false;
        return;
    }

    if (!is_vaild(word_matrix[row][col])) // 如果当前字母不属于yizhong 直接返回
    {
        is_yizhong = false;
        mask_matrix[row][col] = not_yizhong;

        return;
    }

    if (dep == MaxDep && word_matrix[row][col] == 'g')
    {
        is_yizhong = true;
        mask_matrix[row][col] = belong_yizhong;

        return;
    }

    if (word_matrix[row][col] == yizhong[dep - 1]) // 当前深度是否满足对应字母
    {
        // 遍历递归第一个方向
        dfs8(row + 1, col + 1, dep + 1);

        if (is_yizhong)
        {
            mask_matrix[row][col] = belong_yizhong;
        }
    }
    else
    {
        is_yizhong = false;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>word_matrix[i][j];
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> word_matrix[i];
    // }
    is_yizhong = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 遍历八个方向
            // 如果不属于yizhong 那么直接跳过
            if (mask_matrix[i][j] == not_yizhong)
                continue;

            is_yizhong = false;
            dfs1(i, j, 1);

            is_yizhong = false;
            dfs2(i, j, 1);

            is_yizhong = false;
            dfs3(i, j, 1);

            is_yizhong = false;
            dfs4(i, j, 1);

            is_yizhong = false;
            dfs5(i, j, 1);

            is_yizhong = false;
            dfs6(i, j, 1);

            is_yizhong = false;
            dfs7(i, j, 1);

            is_yizhong = false;
            dfs8(i, j, 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(mask_matrix[i][j] == belong_yizhong) cout<<word_matrix[i][j];
            else cout<<'*';
        }

        cout<<'\n';
    }

    return 0;
}