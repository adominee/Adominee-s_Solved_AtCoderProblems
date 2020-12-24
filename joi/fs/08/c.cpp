/*
https://www.nicovideo.jp/watch/sm36175418
勉強になった動画
めっちゃわかりやすかった。
事前にこの動画を見ていたこともあって実質解説Submit......
ただ、半分全列挙の解法を学べてすごいためになった。
見てなかったら絶対解けてない。
動画すごい
動画の解法はあらかじめ2本の矢の得点を全列挙。配列に記憶。
公式解法と同じだ。
その後、残り2本を全探索し、二分探索で先に決めた二本の矢の得点を決めるものだった。
その通りに実装できた気がする。
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

ll n,m;
vector<ll> a,b;

bool isOK(int index,ll key){
    if(b[index]<=key)return true;
    else return false;
}

int nibun(ll key){
    int ok=0,ng=b.size()+1;

    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;

        if(isOK(mid,key))ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
    ll ans=0;
    cin>>n>>m;
    rep(i,n){
        int x;
        cin>>x;
        a.pb(x);
    }
    a.pb(0);
    rep(i,n+1){
        REP(j,i,n+1)b.pb(a[i]+a[j]);
    }
    sort(ALL(b));
    rep(i,b.size()){
        ll cnt=b[i]+b[nibun(m-b[i])];
        if(cnt<=m)chmax(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
/*
半分前列挙
二分探索で3本めと4本目を決める。
この時、m-cntを超えない値にしたい。
*/