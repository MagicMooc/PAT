#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 30;
int l[N], r[N], v[N], h[N], q[N], pos[N];
int n, idx = 0;
void update(int u)
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

void R(int &u)
{
    int p = l[u];
    l[u] = r[p];
    r[p] = u;
    update(u);
    update(p);
    u = p;
}

void L(int &u)
{
    int p = r[u];
    r[u] = l[p];
    l[p] = u;
    update(u);
    update(p);
    u = p;
}

void insert(int &u, int w)
{
    if (!u)
    {
        u = ++idx;
        v[u] = w;
    }
    else if (w < v[u])
    {
        insert(l[u], w);
        if (get_balance(u) == 2)
        {
            if (get_balance(l[u]) == 1)
            {
                R(u);
            }
            else
            {
                L(l[u]);
                R(u);
            }
        }
    }
    else
    {
        insert(r[u], w);
        if (get_balance(u) == -2)
        {
            if (get_balance(r[u]) == -1)
            {
                L(u);
            }
            else
            {
                R(r[u]);
                L(u);
            }
        }
    }
    update(u);
}

bool bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    pos[u] = 1;
    bool res = true;
    while (hh <= tt)
    {
        int t = q[hh++];
        if (pos[t] > n)
        {
            res = false;
        }
        if (l[t])
        {
            q[++tt] = l[t];
            pos[l[t]] = pos[t] * 2;
        }
        if (r[t])
        {
            q[++tt] = r[t];
            pos[r[t]] = pos[t] * 2 + 1;
        }
    }
    return res;
}

int main()
{
    cin >> n;
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        insert(root, w);
    }
    bool res = bfs(root);
    cout << v[q[0]];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << v[q[i]];
    }
    cout << endl;
    if (res)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}