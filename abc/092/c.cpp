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
  vi a(n);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    if(i==0)sum+=abs(a[i]);
    else sum+=abs(a[i]-a[i-1]);
  }
  sum+=abs(a[n-1]);
  rep(i,n){
    ll x,y;
    if(i==0){
      x=abs(a[i])+abs(a[i+1]-a[i]);
      y=abs(a[i+1]);
    }
    else if(i==n-1){
      x=abs(a[i]-a[i-1])+abs(a[i]);
      y=abs(a[i-1]);
    }
    else{
      x=abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
      y=abs(a[i+1]-a[i-1]);
    }
    cout<<sum-x+y<<endl;
  }
  return 0;
}
/*

*/