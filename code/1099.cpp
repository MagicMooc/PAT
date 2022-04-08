#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
int n;
int l[N], r[N], a[N], w[N], q[N];

void dfs(int u, int &k)
{
    if (u == -1)
    {
        return;
    }
    dfs(l[u], k);
    w[u] = a[k++];
    dfs(r[u], k);
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
    cout << w[q[0]];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << w[q[i]];
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = 0;
    dfs(0, k);
    bfs(0);
    return 0;
}