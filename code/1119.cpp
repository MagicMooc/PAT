#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 40;
int preorder[N], postorder[N];
int n;

int build(int prel, int prer, int postl, int postr, string &in)
{
    if (prel > prer)
    {
        return 1;
    }
    if (preorder[prel] != postorder[postr])
    {
        return 0;
    }
    int cnt = 0;
    for (int k = prel; k <= prer; k++)
    {
        string lin, rin;
        int lcnt = build(prel + 1, k, postl, postl + (k - prel - 1), lin);
        int rcnt = build(k + 1, prer, postl + (k - prel - 1) + 1, postr - 1, rin);
        if (lcnt && rcnt)
        {
            in = lin + to_string(preorder[prel]) + " " + rin;
            cnt += lcnt * rcnt;
            if (cnt > 1)
            {
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    string in;
    int cnt = build(0, n - 1, 0, n - 1, in);
    in.pop_back();

    if (cnt > 1)
    {
        puts("No");
    }
    else
    {
        puts("Yes");
    }
    cout << in << endl;

    return 0;
}