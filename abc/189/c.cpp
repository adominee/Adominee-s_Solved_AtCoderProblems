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
  ll ans=0;
  cin>>n;
  vi a(n+1,0);
  rep(i,n)cin>>a[i];
  stack<pair<ll,ll>> st;
  rep(i,n+1){
    if(st.empty()){
      st.emplace(a[i],i);
      continue;
    }
    if(a[i]>st.top().first){
      st.emplace(a[i],i);
      continue;
    }
    if(a[i]==st.top().first)continue;
    ll target;
    while(!st.empty()&&st.top().first>=a[i]){
      chmax(ans,ll((i-st.top().second)*st.top().first));
      target=st.top().second;
      st.pop();
      //cout<<i<<" "<<p<<" "<<ans<<endl;
    }
    st.emplace(a[i],target);
  }
  cout<<ans<<endl;
  return 0;
}
/*
区間和はO(1)
*/