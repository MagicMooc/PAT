#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int n, max_depth = 0, idx = 0;
int l[N], r[N], cnt[N], v[N];

void insert(int &u, int w)
{
    if (u == 0)
    {
        u = ++idx;
        v[u] = w;
        return;
    }
    if (w <= v[u])
    {
        insert(l[u], w);
    }
    else
    {
        insert(r[u], w);
    }
}

void dfs(int u, int depth)
{
    if (!u)
    {
        return;
    }
    cnt[depth]++;
    max_depth = max(depth, max_depth);
    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);
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
    dfs(root, 0);
    int n1 = cnt[max_depth];
    int n2 = cnt[max_depth - 1];
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}