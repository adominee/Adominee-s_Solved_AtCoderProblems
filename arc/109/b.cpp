/*
解説Submit
1からkまでの総和は k(k+1)/2で表せる
nからこのk本の丸太を引いた数+1が答え
2e9とは2*10**nのこと
2e9である理由はk*(k+1)/2のkが2e9の時1e18を超えるから。
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

bool isOK(ll num,ll key){
    if(num*(num+1)/2<=key+1)return true;
    else return false;
}

int main(){
    ll n;
    cin>>n;
    ll ok=0,ng=2e9;
    while(abs(ng-ok)>1){
        ll mid=(ok+ng)/2;

        if(isOK(mid,n))ok=mid;
        else ng=mid;
    }
    cout<<n-ok+1<<endl;
    return 0;
}

//nのパリティ
/*
n=9
10={1,9}
9={2,7}
7={3,4}
n=5
6={3,3},{2,4},{1,5}
6={1,5}
5={1,4},{2,3}

6=1,5
5=2,3
4
ans=3

6=2,4
5
4=1,3
1,2,3,4,5
n=3
4={1,3}
2

偶数
n=10
11={1,10}

11={2,9}
9={3,6}

n=4
5={2,3}
4
1
*/