#include <iostream>
#include <stack>

using namespace std;
const int N = 40;
int n;
int l[N], r[N];
int preorder[N], inorder[N], postorder[N], pos[N];
int pp, ii, t;

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
    postorder[t++] = u;
}

int main()
{
    cin >> n;
    stack<int> stk;
    for (int i = 0; i < n * 2; i++)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            stk.push(x);
            preorder[pp++] = x;
        }
        else
        {
            inorder[ii] = stk.top();
            pos[inorder[ii]] = ii;
            stk.pop();
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