#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int n;
    vi cnt(4,0);
    cin>>n;
    vector<string> s(n),t(n);
    rep(i,n)cin>>s[i];
    rep(i,n)cin>>t[i];
    rep(i,n){
        rep(j,n){
            if(s[i][j]!=t[i][j])cnt[0]++;
            if(s[j][n-i-1]!=t[i][j])cnt[1]++;
            if(s[n-j-1][i]!=t[i][j])cnt[2]++;
            if(s[n-i-1][n-j-1]!=t[i][j])cnt[3]++;
        }
    }
    cnt[1]++,cnt[2]++,cnt[3]+=2;
    cout<<*min_element(ALL(cnt))<<endl;
    return 0;
}
/*
0 2

123
234
345

321
432
543
*/