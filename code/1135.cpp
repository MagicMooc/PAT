#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 40;
int n;
int pre[N], in[N];
unordered_map<int, int> pos;
bool res;

int build(int il, int ir, int pl, int pr, int &sum)
{
    int root = pre[pl];
    int k = pos[abs(root)];
    if (k < il || k > ir)
    {
        res = false;
        return 0;
    }
    int left = 0, right = 0, ls = 0, rs = 0;
    if (k > il)
    {
        left = build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), ls);
    }
    if (k < ir)
    {
        right = build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, rs);
    }

    if (ls != rs)
    {
        res = false;
    }
    sum = ls;

    if (root < 0)
    {
        if (left < 0 || right < 0)
        {
            res = false;
        }
    }
    else
    {
        sum++;
    }

    return root;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
            in[i] = abs(pre[i]);
        }
        sort(in, in + n);
        pos.clear();
        for (int i = 0; i < n; i++)
        {
            pos[in[i]] = i;
        }
        int sum = 0;
        res = true;
        int root = build(0, n - 1, 0, n - 1, sum);
        if (root < 0)
        {
            res = false;
        }
        if (res)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}