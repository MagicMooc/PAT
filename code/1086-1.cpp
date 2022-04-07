#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
const int N = 40;
int preorder[N], inorder[N], postorder[N], pos[N], l[N], r[N];
int n, cnt = 0;

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    if (k > il)
    {
        l[root] = build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il));
    }
    if (k < ir)
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
    postorder[cnt++] = u;
}

int main()
{
    cin >> n;
    stack<int> stk;
    int pi = 0, ii = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            stk.push(x);
            preorder[pi++] = x;
        }
        else
        {
            inorder[ii] = stk.top();
            stk.pop();
            pos[inorder[ii]] = ii;
            ii++;
        }
    }

    int root = build(0, n - 1, 0, n - 1);
    dfs(root);
    cout << postorder[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << postorder[i];
    }
    cout << endl;

    return 0;
}