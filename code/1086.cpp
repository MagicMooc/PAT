#include <iostream>
#include <stack>

using namespace std;
const int N = 40;
int n;
int l[N], r[N];
int postorder[N], cnt = 0;

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
    int type, last = 0;
    int root;
    stack<int> stk;
    for (int i = 0; i < n * 2; i++)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            if (!last)
            {
                root = x;
            }
            else if (type == 0)
            {
                l[last] = x;
            }
            else
            {
                r[last] = x;
            }
            stk.push(x);
            last = x;
            type = 0;
        }
        else
        {
            last = stk.top();
            stk.pop();
            type = 1;
        }
    }
    dfs(root);
    cout << postorder[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << postorder[i];
    }
    cout << endl;
    return 0;
}