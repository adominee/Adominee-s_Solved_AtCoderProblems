/*
解説Submit
https://drken1215.hatenablog.com/entry/2018/10/17/091800
勉強させていただいた記事
ちゃんと手元で検証する癖をつけないとですね……
どうしたら答えだと言えるのかは分かったが、、
そこに至る過程がだめだな
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
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll g=GCD(n,m),res=LCM(n,m);
    n/=g,m/=g;
    bool ok=true;
    rep(i,g){
        if(s[i*n]!=t[i*m])ok=false;
    }
    if(ok)cout<<res<<endl;
    else cout<<-1<<endl;
    return 0;
}
/*
L=6,N=3,M=2
L/N=2
1,3,5
L/M=3
1,4
最小公倍数を求める
それに数字をかけながら、文字が被らないかを確認
もし被ったときは、同じ文字なら大丈夫だが、違う文字ならだめ
-1を出力するのは、最小公倍数のn倍が
*/