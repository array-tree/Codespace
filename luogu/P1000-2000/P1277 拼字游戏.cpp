#include <bits/stdc++.h>
using namespace std;
int ju[10][10];
int row[10];   //每一行还能填的数的限制
int col[10];   //每一列还能填的数的限制
int dui[10];   //每一对角线还能填的数的限制
int lefr[100]; //每一行剩余的还能填的个数
int lefc[100]; //每一列
int lefd[100]; //对角线
int is_dui(int x, int y)
{
    if (x == y)
    {
        return 1; //在主对角线上
    }
    if (x + y == 5)
    {
        return 2; //在副对角线上
    }
    return 0; //不在对角线上
}
int the_min[100][1000];
struct node
{
    int shu;
    int x, y;
    int max_; //这一个格子所能填入的最大值
};
vector<node> nodes; //格子序列
node maker(int x, int y, int max_)
{
    node insid;
    insid.max_ = max_;
    // insid.shu=shu;
    insid.x = x;
    insid.y = y;
    return insid;
}
bool cmp(node a, node b)
{
    return a.max_ < b.max_;
}
bool continue_tag = 1;
bool checker()
{
    for (int yy = 1; yy <= 4; yy++)
    {
        if (row[yy])
        {
            return 0;
        }
    }
    for (int yy = 1; yy <= 4; yy++)
    {
        if (col[yy])
        {
            return 0;
        }
    }
    for (int yy = 1; yy <= 2; yy++)
    {
        if (dui[yy])
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int k)
{
    //cout<<k<<endl;
    int xx, yy;
    //if (continue_tag == 0)
    //{
    //    return;
    //}
    if (k == nodes.size())
    {
        if (checker())
        {
            for (int xx = 1; xx <= 4; xx++)
            {
                for (int yy = 1; yy <= 4; yy++)
                {
                    cout << ju[xx][yy] << " ";
                }
                cout << "\n";
            }
            exit(0);
            continue_tag = 0;
            return;
        }
    }
    else
    {
        xx = nodes[k].x;
        yy = nodes[k].y;
        int the_max = min(nodes[k].max_, min(col[yy], row[xx]));

        int dtag = is_dui(xx, yy);
        if (dtag == 0) //不是对角线
        {
            lefc[yy]--;
            lefr[xx]--;
            for (int i = the_max; i >= 1; i--)
            {
                ju[xx][yy] = i;
                row[xx] -= i;
                col[yy] -= i;
                if (lefr[xx] == 0 && row[xx])
                {
                    ju[xx][yy] = 0;
                    row[xx] += i;
                    col[yy] += i;
                    continue;
                }
                if (lefc[yy] == 0 && col[yy])
                {
                    ju[xx][yy] = 0;
                    row[xx] += i;
                    col[yy] += i;
                    continue;
                }

                dfs(k + 1);
                ju[xx][yy] = 0;
                row[xx] += i;
                col[yy] += i;
            }
            lefc[yy]++;
            lefr[xx]++;
        }
        else
        {
            lefc[yy]--;
            lefr[xx]--;
            lefd[dtag]--;
            the_max = min(the_max, dui[dtag]);

            for (int i = the_max; i >= 1; i--)
            {

                ju[xx][yy] = i;
                row[xx] -= i;
                col[yy] -= i;
                dui[dtag] -= i;
                if (lefr[xx] == 0 && row[xx])
                {
                    ju[xx][yy] = 0;
                    row[xx] += i;
                    col[yy] += i;
                    dui[dtag] += i;
                    continue;
                }
                if (lefc[yy] == 0 && col[yy])
                {
                    ju[xx][yy] = 0;
                    row[xx] += i;
                    col[yy] += i;
                    dui[dtag] += i;
                    continue;
                }
                if (lefd[dtag] == 0 && dui[dtag])
                {
                    ju[xx][yy] = 0;
                    row[xx] += i;
                    col[yy] += i;
                    dui[dtag] += i;
                    continue;
                }
                dfs(k + 1);
                ju[xx][yy] = 0;
                row[xx] += i;
                col[yy] += i;
                dui[dtag] += i;
            }
            lefc[yy]++;
            lefr[xx]++;
            lefd[dtag]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);

    for (int ww = 1; ww <= 4; ww++)
    {
        cin >> row[ww];
        lefr[ww] = 4;
    }
    for (int ww = 1; ww <= 4; ww++)
    {
        cin >> col[ww];
        lefc[ww] = 4;
    }
    for (int ww = 1; ww <= 2; ww++)
    {
        cin >> dui[ww];
        lefd[ww] = 4;
    }
    int x, y, zhi;
    for (int ww = 1; ww <= 4; ww++)
    {
        cin >> x >> y >> zhi;
        x++;
        y++;
        ju[x][y] = zhi;
    }
    for (int ee = 1; ee <= 4; ee++)
    {
        int min_ = row[ee];
        for (int ww = 1; ww <= 4; ww++)
        {
            min_ -= ju[ee][ww];
        }
        for (int ww = 1; ww <= 4; ww++)
        {
            the_min[ee][ww] = min_;
        }
        row[ee] = min_;
    }
    for (int ee = 1; ee <= 4; ee++)
    {
        int min_ = col[ee];
        for (int ww = 1; ww <= 4; ww++)
        {
            min_ -= ju[ww][ee];
        }
        for (int ww = 1; ww <= 4; ww++)
        {
            the_min[ww][ee] = min(the_min[ww][ee], min_);
        }
        col[ee] = min_;
    }

    dui[1] = dui[1] - (ju[1][1] + ju[2][2] + ju[3][3] + ju[4][4]);
    dui[2] = dui[2] - (ju[1][4] + ju[2][3] + ju[3][2] + ju[4][1]);
    for (int ww = 1; ww <= 4; ww++)
    {
        the_min[ww][ww] = min(the_min[ww][ww], dui[1]);
        if (ju[ww][ww])
        {
            lefd[1]--;
        }
    }
    for (int ww = 1; ww <= 4; ww++)
    {
        the_min[ww][5 - ww] = min(the_min[ww][5 - ww], dui[2]);
        if (ju[ww][5 - ww])
        {
            lefd[2]--;
        }
    }
    for (int xx = 1; xx <= 4; xx++)
    {
        for (int yy = 1; yy <= 4; yy++)
        {
            if (ju[xx][yy] == 0)
            {
                nodes.push_back(maker(xx, yy, the_min[xx][yy]));
            }
            else
            {
                lefr[xx]--;
                lefc[yy]--;
            }
        }
    }
    sort(nodes.begin(), nodes.end(), cmp);
    dfs(0);
    return 0;
}