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
  string s;
  vector<bool> a(101,false);
  ll k,cnt=0;
  cin>>s>>k;
  if(s.length()==1){
    cout<<k/2<<endl;
    return 0;
  }
  else if(s.length()==2){
    if(s[0]==s[1])cout<<k<<endl;
    else cout<<0<<endl;
    return 0;
  }
  rep(i,s.length()-1){
    if(s[i]==s[i+1]&&!a[i]){
      cnt++;
      a[i+1]=true;
    }
  }
  cnt*=k;
  if(s[0]==*(s.end()-1)&&!a[s.length()-1])cnt+=k-1;
  cout<<cnt<<endl;
  return 0;
}
/*

*/