#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010, M = N * 2;

int h[N], e[M], ne[M], idx, p[N];
int n;

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u, int father)
{
    int depth = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        depth = max(depth, dfs(j, u) + 1);
    }
    return depth;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    int k = n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
        {
            k--;
            p[find(b)] = find(a);
        }
        add(a, b);
        add(b, a);
    }
    if (k > 1)
    {
        printf("Error: %d components", k);
    }
    else
    {
        int max_depth = -1;
        vector<int> nodes;
        for (int i = 1; i <= n; i++)
        {
            int depth = dfs(i, -1);
            if (depth > max_depth)
            {
                max_depth = depth;
                nodes.clear();
                nodes.push_back(i);
            }
            else if(depth == max_depth)
            {
                nodes.push_back(i);
            }
        }
        for (auto v : nodes)
        {
            cout << v << endl;
        }
    }
    return 0;
}
