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
  vii graph(n,vi());
  vector<pair<int,int>> edge(n-1);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--,b--;
    graph[a].pb(b);
    graph[b].pb(a);
    edge[i]={a,b};
  }
  int d=0;
  rep(i,n)chmax(d,int(graph[i].size()));
  map<pair<int,int>,int> mp;
  queue<pair<int,int>>que;
  vector<bool> dist(n,false);
  mp[{0,0}]=-1;
  dist[0]=true;
  que.emplace(0,0);
  int l=0;
  while(!que.empty()){
    int point=que.front().first,pre=que.front().second;
    que.pop();
    int colored=mp[{min(point,pre),max(point,pre)}],color=0;
    for(auto x:graph[point]){
      if(pre==x)continue;
      if(dist[x])continue;
      if(color==colored)color++;
      mp[{min(point,x),max(point,x)}]=color;
      dist[x]=true;
      que.emplace(x,point);
      color++;
    }
    //cout<<point<<" "<<pre<<endl;
  }
  cout<<d<<endl;
  rep(i,n-1){
    cout<<mp[edge[i]]+1<<endl;
  }
  return 0;
}
/*
過去の提出を見返したら頂点に色を塗るのはその頂点に到達するために通った辺に塗る色と同色でもよいという発見があった。
*/