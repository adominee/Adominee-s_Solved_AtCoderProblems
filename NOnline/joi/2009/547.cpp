#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int MOD=100000;
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
    while(1){
        int w,h;
        ll ans=0;
        cin>>w>>h;
        if(!w&&!h)break;
        int dp[h+2][w+2][3];
        rep(i,h+2)rep(j,w+2)rep(k,3)dp[i][j][k]=0;
        dp[1][1][0]=1;
        rep(i,h){
            rep(j,w){
                if(i==0&&j==0)continue;
                dp[i+1][j+1][0]=(dp[i+1][j][0]+dp[i][j+1][0]+dp[i+1][j][1]+dp[i][j+1][1])%MOD;
                dp[i+1][j+1][1]=(dp[i+1][j][0]+dp[i][j+1][0])%MOD;
                cout<<"i:"<<i+1<<"j:"<<j+1<<" "<<dp[i+1][j+1][0]<<" "<<dp[i+1][j+1][1]<<endl;
            }
        }
        cout<<(dp[h][w][0]+dp[h][w][1])%MOD<<endl;
    }
    return 0;
}