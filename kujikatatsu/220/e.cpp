//解説AC
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
  int n,m;
  cin>>n>>m;
  vii a(n,vi(3));
  rep(i,n){
    rep(j,3)cin>>a[i][j];
  }
  ll Max=0;
  rep(bit,8){
    vi vec;
    rep(j,n){
      ll s=0;
      rep(k,3){
        if((bit/(1<<k))%2==0)s+=a[j][k];
        else s-=a[j][k];
      }
      vec.pb(s);
    }
    sort(ALL(vec));
    rv(ALL(vec));
    ll ans=0;
    for(int j=0;j<m;j++)ans+=vec[j];
    chmax(Max,ans);
  }
  cout<<Max<<endl;
  return 0;
}
/*

*/