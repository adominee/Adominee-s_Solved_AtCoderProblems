/*
勉強させていただいた記事
http://algoogle.hadrori.jp/joi/sc2007building/
値の変遷を見てると値自体が表す意味は広いみたい？
実際にはとり得ない値が入っていても答えとしては問題がない。
更新された値にその前の値の意味があることも。重要なのは連続性？
DPの本質感がある。

lower_boundについて勉強させていただいた
https://qiita.com/ganariya/items/33f1326154b85db465c3
あるキーのイテレータから先頭のイテレータを引くとキー未満の要素の個数がある。
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

int main(){
    int n;
    cin>>n;
    vi h(n);
    rep(i,n)cin>>h[i];
    vi dp(n,INF);
    rep(i,n){
        //二分探索を用いてh[i]の最適な挿入位置を探して入れる。
        *lower_bound(ALL(dp),h[i])=h[i];
        //for(auto x:dp)cout<<x<<" ";
        //cout<<endl;
    }
    //for(auto x:dp)cout<<x<<endl;
    cout<<lower_bound(ALL(dp),INF)-dp.begin()<<endl;
    return 0;
}