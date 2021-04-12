/***
            Bismillahir Rahmanir Rahim
            Read the name of Allah, who created you!!!
            Author : Shah Newaj Rabbi Shishir
            Department of CSE, City University, Bangladesh.
***/

#include <bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define ssf sscanf
#define spf sprintf
#define fsf fscanf
#define fpf fprintf
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define scase sf("%d", &tc)
#define sn sf("%d", &n)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos = 1; pos <= tc; pos++)
#define arrayloop (i = 0; i < n; i++)
#define cinstr cin >> str
#define getstr getline(cin, str)
#define pcase pf("Case %d: ", pos)
#define pii pair<int, int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int
#define endl "\n"

const int MOD = 1000000007;
const int MAX = 100000001;

bool prime[MAX];
U arr[MAX];

void sieve()
{
    U i, j;

    arr[2] = 1;

    prime[0] = prime[1] = true;

    for (i = 4; i < MAX; i += 2)
        prime[i] = true;

    for (i = 3; i * i <= MAX; i += 2)
        if (!prime[i])
            for (j = i * i; j < MAX; j += 2 * i)
                prime[j] = true;

    for (i = 3; i < MAX; i += 2)
    {
        if (!prime[i])
            arr[i + 1] = arr[i] = arr[i - 1] + 1;
        else
            arr[i + 1] = arr[i] = arr[i - 1];
    }
}

int main(void)
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    */
    sieve();

    int n;
    double x, y, res;

    while (sf("%u", &n) && n)
    {
        x = arr[n];
        y = double(n) / log(double(n));
        y = abs(x - y);
        res = (y / x) * 100;
        pf("%0.1lf\n", res);
    }

    return 0;
}