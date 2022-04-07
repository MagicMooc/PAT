#include <iostream>
#include <stack>

using namespace std;
const int N = 40;
int l[N], r[N];
int n;

void dfs(int u, int root)
{
    if (!u)
    {
        return;
    }
    dfs(l[u], root);
    dfs(r[u], root);
    cout << u;
    if (u != root)
    {
        cout << ' ';
    }
}

int main()
{
    cin >> n;
    int type, last = 0, root;
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
            else
            {
                if (type == 0)
                {
                    l[last] = x;
                }
                else
                {
                    r[last] = x;
                }
            }
            last = x;
            stk.push(x);
            type = 0;
        }
        else
        {
            last = stk.top();
            stk.pop();
            type = 1;
        }
    }

    dfs(root, root);
    return 0;
}