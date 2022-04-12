#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 40;
int n;
unordered_map<int, int> l, r, pos;
int inorder[N], postrorder[N], q[N];

int build(int il, int ir, int pl, int pr)
{
    int root = postrorder[pr];
    int k = pos[root];
    if (k > il)
    {
        l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
    }
    if (k < ir)
    {
        r[root] = build(k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
    }
    return root;
}

void bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    int tag = 0;
    while (hh <= tt)
    {
        int head = hh, tail = tt;
        while (hh <= tail)
        {
            int t = q[hh++];
            if (l.count(t))
            {
                q[++tt] = l[t];
            }
            if (r.count(t))
            {
                q[++tt] = r[t];
            }
        }
        if (++tag % 2)
        {
            reverse(q + head, q + tail + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postrorder[i];
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    cout << q[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << q[i];
    }
    cout << endl;
    return 0;
}