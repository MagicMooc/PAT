#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
int n, l[N], r[N];
bool has_father[N];
int maxk, maxid;

void dfs(int u, int k)
{
    if (u == -1)
    {
        return;
    }
    if (k > maxk)
    {
        maxk = k;
        maxid = u;
    }
    dfs(l[u], 2 * k);
    dfs(r[u], 2 * k + 1);
}

int main()
{
    cin >> n;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for (int i = 0; i < n; i++)
    {
        string ls, rs;
        cin >> ls >> rs;
        if (ls != "-")
        {
            l[i] = stoi(ls);
            has_father[l[i]] = true;
        }
        if (rs != "-")
        {
            r[i] = stoi(rs);
            has_father[r[i]] = true;
        }
    }
    int root = 0;
    while (has_father[root])
    {
        root++;
    }
    dfs(root, 1);
    if (maxk == n)
    {
        printf("YES %d", maxid);
    }
    else
    {
        printf("NO %d", root);
    }
}