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
  ll n,d=-1;
  cin>>n;
  vii graph(n);
  vector<pll> p;
  map<pll,int>mp;
  mp[{0,-1}]=-1;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--,b--;
    p.pb({a,b});
    graph[a].pb(b);
    graph[b].pb(a);
  }
  rep(i,n)chmax(d,ll(graph[i].size()));
  queue<pll>que;
  que.emplace(0,-1);
  while(!que.empty()){
    auto& [a,b]=que.front();
    que.pop();
    ll uc=mp[{min(a,b),max(a,b)}],color=1;
    for(auto x:graph[a]){
      if(x==b||mp[{min(a,x),max(a,x)}]!=0){
        continue;
      }
      if(color==uc)color++;
      mp[{min(a,x),max(a,x)}]=color;
      color++;
      que.emplace(x,a);
    }
  }
  cout<<d<<endl;
  for(auto& [a,b]:p){
    cout<<mp[{a,b}]<<endl;
  }
  return 0;
}
/*

*/