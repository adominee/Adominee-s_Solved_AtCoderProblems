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
    int n,m,ans=INF;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,n)cin>>s[i];
    vii flag(n+1,vi(3,0));
    rep(i,n){
        vi color(3,0);
        rep(j,m){
            if(s[i][j]=='W')color[0]++;
            else if(s[i][j]=='B')color[1]++;
            else if(s[i][j]=='R')color[2]++;
        }
        rep(j,3){
            flag[i+1][j]=flag[i][j]+color[j];
        }
    }
    rep(i,n-2){
        REP(j,i,n-1){
            int cw=flag[i+1][1]+flag[i+1][2];
            int cb=flag[j+1][0]+flag[j+1][2]-flag[i+1][0]-flag[i+1][2];
            int cr=flag[n][0]+flag[n][1]-flag[j+1][0]-flag[j+1][1];
            ans=min(ans,cw+cb+cr);
        }
    }
    cout<<ans<<endl;
    return 0;
}