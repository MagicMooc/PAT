#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 50010;
unordered_map<int, int> l, r, pos;
int pre[N], in[N], post[N], cnt = 0;
int n;

int build(int il, int ir, int pl, int pr)
{
    int root = pre[pl];
    int k = pos[root];
    if (il < k)
    {
        l[root] = build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il));
    }
    if (ir > k)
    {
        r[root] = build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr);
    }
    return root;
}

void dfs(int u)
{
    if (!u)
    {
        return;
    }
    dfs(l[u]);
    dfs(r[u]);
    post[cnt++] = u;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        pos[in[i]] = i;
    }
    int root = build(0, n - 1, 0, n - 1);
    dfs(root);
    cout << post[0] << endl;
    return 0;
}