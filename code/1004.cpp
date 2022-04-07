#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int h[N], e[N], ne[N], idx = 0;
int max_depth, cnt[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int depth)
{
    if(h[u]==-1){
        cnt[depth]++;
        max_depth = max(depth, max_depth);
        return;
    }
    for (int i = h[u]; ~i; i = ne[i]){
        dfs(e[i], depth + 1);
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int id, k;
        cin >> id >> k;
        for (int i = 0; i < k; i++)
        {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    dfs(1, 0);
    cout << cnt[0];
    for (int i = 1; i <= max_depth; i++)
    {
        cout << ' ' << cnt[i];
    }
    cout << endl;
    return 0;
}