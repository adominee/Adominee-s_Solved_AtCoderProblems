/*
https://h1guch.hatenablog.com/entry/2020/02/24/213611
勉強させていただいた記事
私がやりたかったことが解説されている。
めっちゃわかりやすい
一つ前と、そのもう一つ前に縦に進んだのか、横に進んだのかの状態を持つのか……
確かに水平と垂直じゃ謎の状態だ
縦と横の組み合わせはたかだか4通り。
0=縦縦
1=縦横
2=横縦
3=横横
dp[i][j][k]:=i行j列、来た経路の方向。
*/

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

const int MOD=1e5;
int dp[110][110][4];

int main(){
    int w,h;
    ll ans=0;
    cin>>w>>h;
    REP(i,1,h)dp[i][0][0]=1;
    REP(i,1,w)dp[0][i][3]=1;
    rep(i,h){
        rep(j,w){
            if(i==0||j==0)continue;
            dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][2];
            dp[i][j][2]+=dp[i-1][j][3];
            dp[i][j][3]+=dp[i][j-1][3]+dp[i][j-1][1];
            dp[i][j][1]+=dp[i][j-1][0];
            rep(k,4)dp[i][j][k]%=MOD;
        }
    }
    rep(i,4)ans=(ans+dp[h-1][w-1][i])%MOD;
    cout<<ans<<endl;
    return 0;
}
/*
DP
dp[i][j][k][l]:=i行j列において、右か上かを保持しつつ、曲がったかどうかも保持し
そこまでの経路。
遷移を考える
1は水平,0は垂直
右に進むときは？
dp[i+1][j][1][0]+=dp[i][j][1][0]+dp[i][j][1][1]
dp[i+1][j][1][1]+=dp[i][j][0][0]
上に進むときは？
dp[i][j+1][0][0]=dp[i][j][0][0]+dp[i][j][0][1]
dp[i+1][j][0][1]=dp[1][0]


流石に添字が多すぎた。
公式解説めっちゃシンプル
そもそもdpですらない？
でもこういう経路の問題ってdpなイメージ
点で考えるのではなく辺かー
なかなか、添字多いわけではなく、DPでも解ける。

*/