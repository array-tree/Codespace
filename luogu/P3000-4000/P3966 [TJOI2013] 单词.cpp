#include <bits/stdc++.h>
using namespace std;
map<string, int> qq;
int n;
string s[100000];
struct node
{
    int in;
    int fail;
    int ans;
    int son[35];
    int end;
};
node trie[1000000];
int num[100000];
int cnt = 1;
void build(string as, int num) //第num个单词
{
    int l = as.length();
    int now_ = 1;
    for (int ee = 0; ee < l; ee++)
    {
        int name_ = as[ee] - 'a';
        if (trie[now_].son[name_] == 0)
        {
            cnt++;
            trie[now_].son[name_] = cnt;
        }
        now_ = trie[now_].son[name_];
    }
    trie[now_].end = num;
}
queue<int> q;
void get_fail()
{
    for (int yy = 0; yy < 30; yy++)
    {
        trie[0].son[yy] = 1;
    }
    q.push(1);
    trie[1].fail = 0;
    while (!q.empty())
    {
        int now_ = q.front();
        q.pop();
        for (int yy = 0; yy < 30; yy++)
        {
            int son_ = trie[now_].son[yy];
            int fail_ = trie[now_].fail;
            if (son_ == 0) //如果不存在这个儿子
            {
                trie[now_].son[yy] = trie[fail_].son[yy];
                continue;
            }
            trie[son_].fail = trie[fail_].son[yy];
            trie[trie[son_].fail].in++;
            q.push(son_);
        }
    }
}
int query(string sa)
{
    int now_ = 1;
    int ans = 0;
    int len = sa.size();
    for (int i = 0; i < len; i++)
    {
        int name_ = sa[i] - 'a';
        now_ = trie[now_].son[name_];
        trie[now_].ans++;
    }
    
}
void topu()
{
    while (!q.empty())
    {
        q.pop();
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (!trie[i].in)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int now_ = q.front();
        q.pop();
        num[trie[now_].end] = trie[now_].ans;
        trie[trie[now_].fail].in--;
        trie[trie[now_].fail].ans += trie[now_].ans;
        if (trie[trie[now_].fail].in == 0)
        {
            q.push(trie[now_].fail);
        }
    }
}
string ss;
int main()
{
    // ios::sync_with_stdio(false);

    ss.clear();
    cin >> n;
    for (int yy = 1; yy <= n; yy++)
    {
        cin >> s[yy];
        ss += s[yy];
        ss += char('a' + 27);
        qq[s[yy]] = yy;
        build(s[yy], yy);
    }
    get_fail();
    query(ss);
    topu();
    for (int ee = 1; ee <= n; ee++)
    {
        int yy = num[qq[s[ee]]];
        cout << yy << "\n";
    }

    return 0;
}
