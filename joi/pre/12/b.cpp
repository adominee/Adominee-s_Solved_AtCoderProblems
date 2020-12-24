#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF = 1e13 + 7;
const int INF = 1e9 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T, class Y>
T GCD(T a, Y b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    if (a % b == 0)
    {
        return b;
    }
    return GCD(b, a % b);
}
template <class T, class Y>
T LCM(T a, Y b) { return (a * b) / GCD(a, b); }
void clear(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> empty;
    swap(q, empty);
} //queueの中身の型は適時変更を忘れない

using vi = vector<int>;
using vii = vector<vi>;

#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(), (a).end()
#define decimal(x) fixed << setprecision(x)

int main()
{
    int n, cnt = 1;
    cin >> n;
    vii teams(n, vi(3, 0));
    vi points(n, 0);
    map<int, int> mp, rank;
    rep(i, n * (n - 1) / 2)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c > d)
        {
            teams[a - 1][0]++;
            teams[b - 1][1]++;
        }
        else if (c < d)
        {
            teams[b - 1][0]++;
            teams[a - 1][1]++;
        }
        else
        {
            teams[a - 1][2]++;
            teams[b - 1][2]++;
        }
    }
    rep(i, n)
    {
        points[i]=teams[i][0]*3+teams[i][2];
        mp[-points[i]]++;
    }
    for (auto x : mp)
    {
        rank[-x.first] = cnt;
        cnt += x.second;
    }
    for (auto x : points)
        cout << rank[x] << endl;
    return 0;
}