/*
https://qnighy.github.io/informatics-olympiad/joi2010-day1-stairs-comment.html
https://algoogle.hadrori.jp/joi/sc2010stairs/
勉強させていただいた記事
いきなり満点解法に飛ばず、思いついた解法から、どうしたら削れるかを考えるのも大切。
多分解法のパターンはストック溜まった気がしてきてるから、あとは解法から高速化するためのところを考えるところかなぁ
ナップサックdp系だと考えた。
でもどんな遷移で、どんな情報を保持するのかが分からなかった。
だめだ、解法見ても点数とれん
コードを見ます
って思ったけど、最初の20点コード書き換えたら50いけるんじゃないかな？
50点Submit
なるほどなぁ
jをi-1側から見ていけばいいんだ。
60点取れてる
ここでネックとなるのが、総和の計算
ここの計算量を改善するために、尺取り法みたいな処理を行う。
満たしているならr++,満たしていないならl++
段差の一つ前は条件を必ず満たす。また、rとlの区間が条件を満たしている。
そのため、この二つを足したものがr+1段目にいく総数になる。
rとlの間の区間の一つ一つを足す必要があるが、累積和の間隔でrとlの区間和を求めることができる。
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
const int mod=1234567;

int main(){
    int n,p,right=0,left=0;
    ll sum=0;
    cin>>n>>p;
    vi h(n),a(n+1,0);
    a[1]=1;
    rep(i,n)cin>>h[i];
    rep(i,n){
        while(right<=i)sum+=h[right++];
        while(left<right && p<sum)sum-=h[left++];
        a[right+1]=(a[right]+(a[right]-a[left]))%mod;
    }
    //for(auto x:a)cout<<x<<endl;
    if(a[n+1]-a[n]<0)cout<<(a[n+1]-a[n]+mod)%mod<<endl;
    else cout<<(a[n+1]-a[n])%mod<<endl;
    return 0;
}
/*
6 350
315
191
98
70
126
200

*/