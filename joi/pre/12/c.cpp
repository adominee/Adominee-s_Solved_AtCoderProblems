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

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int n,a,b,ans=0,sum;
    cin>>n>>a>>b>>sum;
    vi d(n);
    rep(i,n)cin>>d[i];
    sort(ALL(d),greater<int>());
    rep(i,n){
        sum+=d[i];
        ans=max(ans,sum/(a+b*(i+1)));
    }
    cout<<ans<<endl;
    return 0;
}

/*
多分ナップサック
全部の通りを試す？
もし、一ドルあたりのカロリーが大きくなったら更新
中身はカロリー
添字はi番目のトッピング、トッピングを何個載せたかを表している。
載せる載せない

難しく考えすぎた……
カロリー高い方から載せていけばいいよね……
そしたらどっかでカロリーに対するドルの上がりが少なくなって答えがわかる。
*/