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

ll n,c,ans=0;
vi x(160),v(160);

int bfs(ll point,ll index,ll calory,vector<bool> dist){
  int cnt=0;
  for(auto x:dist)if(x)cnt++;
  if(cnt==n)return calory;
  int a,b,sum1,sum2;
  rep(i,n){
    if(!dist[(index+i+1)%n]){
      a=(index+i+1)%n;
      break;
    }
  }
  dist[a]=true;
  sum1=bfs(x[a],a,calory+v[a]-abs(point-x[a]),dist);
  dist[a]=false;
  rep(i,n){
    int x=(index-i-1<0) ? index-i-1+n:index-i-1; 
    if(!dist[x%n]){
      b=x;
      dist[b]=true;
      break;
    }
  }
  cout<<a<<":"<<b<<endl;
  dist[b]=true;
  sum2=bfs(x[b],b,calory+v[b]-abs(point-x[b]),dist);
  return max(sum1,sum2);
}

int main(){
  cin>>n>>c;
  if(n>150)return 0;
  rep(i,n)cin>>x[i]>>v[i];
  vector<bool> dist(160,false);
  dist[0]=true;
  ll sum1=bfs(x[0],0,v[0]-x[0],dist);
  dist[0]=false;
  dist[n-1]=true;
  ll sum2=bfs(x[n-1],n-1,v[n-1]-(c-x[n-1]),dist);
  cout<<sum1<<" "<<sum2<<endl;
  cout<<max(sum1,sum2)<<endl;
  return 0;
}
/*
右反転、左反転で行うためにDFS?
*/