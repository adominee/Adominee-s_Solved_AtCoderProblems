/*
解説Submit
選ぶ選ばないの2つの選択肢があるので、偶数だけなら2**nだよね
奇数があるときは、一つの奇数以外について考える。
総和が奇数、偶数に応じて一つの奇数を選ぶ、選ばないが決まるので、一つの奇数は影響を及ぼさない。
よって数列から一つの奇数を除いた、n-1
2**(n-1)が奇数が含まれるときの正解である。
言われたらなるほどとなる。
でも考えても出てこない……

powはdouble型で返ってくるので、そのまま出力するとdouble型の指数表示がされてしまうので気をつける。
*/

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
    ll n,p,e=0;
    cin>>n>>p;
    vi a(n);
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==0)e++;
    }
    if(e==n){
        if(p%2==0)cout<<ll(pow(2,n))<<endl;
        else cout<<0<<endl;
    }else{
        cout<<ll(pow(2,n-1))<<endl;
    }

    return 0;
}