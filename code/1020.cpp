#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 40;
int postorder[N], inorder[N], q[N];
unordered_map<int, int> l, r, pos;
int n;

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];
    if (il < k)
    {
        l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
    }
    if (ir > k)
    {
        r[root] = build(k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
    }
    return root;
}

void bfs(int root)
{
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt)
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
    cout << q[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << q[i];
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}