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

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
  int n;
  ll ans=1;
  cin>>n;
  vector<string> s(n);
  vi t(n+1,1),f(n+1,1);
  rep(i,n)cin>>s[i];
  rep(i,n){
    if(s[i]=="OR"){
      t[i+1]=t[i]*2+f[i];
      f[i+1]=f[i];
    }else{
      t[i+1]=t[i];
      f[i+1]=f[i]*2+t[i];
      //ANDとORの性質を考えてtとfを加算する。
      //ANDのとき、xの値がどちらでもfに変わらないので、f[i]に2をかける
      //yが1ならxは0でないと次のyが0にならないので、t[i]をそのまま足す。
    }
  }
  cout<<t[n]<<endl;
  return 0;
}
/*
小さな問題に帰着していくのは思いつかなかった。
そこまでのtrueとfalseを記録して求めるのか―
なんで前はわかったんだ。。？
xがtrueかfalseかで遷移式を書く
OverFlow!!!
*/