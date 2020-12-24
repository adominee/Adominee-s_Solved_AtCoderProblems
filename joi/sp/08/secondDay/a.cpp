/*
http://algoogle.hadrori.jp/joi/sc2008nile/
勉強させていただいたサイト
dpは考えたけど遷移が分からない。
dp[i][j][k] := i日目までに店jで連続k回購入した時の最小コスト
dpに[i][j][k]はi日目の価格を含まず、それ以前の値を持っている。
遷移はi+1日に店jでk+1回購入にその値または、i日に店jでk回購入したものに、その店でi日に買った時の値をk日継続の%で割り引いたものを足したもののうち、
最小のほう
別の店で買うことになると、継続割りがないので最小コストを足して良い。

int型の配列はスコープ内ではなく、その外、グローバル変数としないとだめ？Seg falutする。
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

const int per[]={9,7};
int dp[512][4096][4];

int main(){
    int n,d,m=0,zero;
    cin>>n>>d;
    vii prices(d,vi(n,0));
    rep(i,d){
        rep(j,n){
            cin>>prices[i][j];
        }
    }
    rep(i,d){//d日
        zero=m;//zeroはi日までの最小コスト
        m=1e9;
        rep(j,n){//j店
            //j店で買った値段を、前日までの最小コストを足す
            dp[i+1][j][0]=zero+prices[i][j];
            m=min(m,dp[i+1][j][0]);
            //i日の最小コストを更新
            for(int k=0;k<2;k++){
                //もし遷移元がなければスルー
                if(!dp[i][j][k])continue;
                int nk=1;
                //遷移先があればchmin,ない場合、遷移先は0扱いとなってしまうので、直接代入
                if(dp[i+1][j][nk])chmin(dp[i+1][j][nk],dp[i][j][k]+prices[i][j]/10*per[k]);
                else dp[i+1][j][nk]=dp[i][j][k]+prices[i][j]/10*per[k];
                m=min(m,dp[i+1][j][nk]);
            }
        }
    }
    cout<<m<<endl;
    return 0;
}
/*
DP?
店の情報もいるのでこれじゃ足りない。
i日目にj回そこで買った時の最小値を表す。
各日ごとの値段の最小値の総和が答え。
遷移を考える
i+1日め
*/