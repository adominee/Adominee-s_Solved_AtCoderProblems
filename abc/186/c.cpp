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

void calc(vi& arr,int t){
  arr[0]++;
  if(arr[0]>=t){
    arr[0]=0;
    bool isD=true;
    REP(i,1,10){
      if(isD){
        arr[i]++;
        isD=false;
      }
      if(arr[i]>=t){
        arr[i]=0;
        isD=true;
        continue;
      }
      break;
    }
  }
}

int main(){
  int n,cnt=0;
  cin>>n;
  vi eight(10,0),ten(10,0);
  REP(i,1,n+1){
    calc(eight,8);
    calc(ten,10);
    bool isGood=true;
    for(auto x:eight)if(x==7)isGood=false;
    for(auto x:ten)if(x==7)isGood=false;
    if(isGood)cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
/*

*/