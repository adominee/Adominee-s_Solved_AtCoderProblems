//解説Submit
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
    int n,ans=0;
    cin>>n;
    vi a(n,1);
    rep(i,n){
        int x;
        cin>>x;
        if(x==i+1)a[i]=0;
    }
    rep(i,n){
        if(i==n-1&&a[i]==0){
            a[i]=a[i-1]=1;
            ans++;
            break;
        }
        if(a[i]==0){
            a[i]=a[i+1]=1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
iとPiが一致している区間を数えて、その区間のなかで、スワップを繰り返すと解が出るはず
5
1 4 3 5 2
1 4 3 5 2
4 1 5 3 2

5
1 2 3 4 5
2 3 4 5 1
もし、区間が1のときに、交換するとi=Piが成立するような数は成立しない。
なぜなら、数値は必ず一種類
もっとxとoで簡略にシミュができるんですね……
*/