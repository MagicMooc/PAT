#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 15;
int n;
int l[N], r[N], q[N];
bool has_father[N];
int inorder[N], cnt = 0;

void dfs_reverse(int u)
{
    if (u == -1)
    {
        return;
    }
    dfs_reverse(l[u]);
    dfs_reverse(r[u]);
    swap(l[u], r[u]);
}

void bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    while (hh <= tt)
    {
        int t = q[hh++];
        if (l[t] != -1)
        {
            q[++tt] = l[t];
        }
        if (r[t] != -1)
        {
            q[++tt] = r[t];
        }
    }
    cout << q[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << q[i];
    }
    cout << endl;
}

void dfs(int u)
{
    if (u == -1)
    {
        return;
    }
    dfs(l[u]);
    inorder[cnt++] = u;
    dfs(r[u]);
}

int main()
{
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char lc, rc;
        cin >> lc >> rc;
        if (lc != '-')
        {
            l[i] = lc - '0';
            has_father[l[i]] = true;
        }
        if (rc != '-')
        {
            r[i] = rc - '0';
            has_father[r[i]] = true;
        }
    }

    int root = 0;

    while (has_father[root])
    {
        root++;
    }
    dfs_reverse(root);
    bfs(root);
    dfs(root);
    cout << inorder[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << inorder[i];
    }
    cout << endl;

    return 0;
}