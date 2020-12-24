#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e6;
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
    int m,n,a,b,ans=1e9;
    cin>>m>>n>>a>>b;
    vii Block(n+1,vi(m+1,0));
    rep(i,n){
        rep(j,m){
            int x;
            cin>>x;
            if(x==-1)x=INF;
            Block[i+1][j+1]=Block[i+1][j]+Block[i][j+1]-Block[i][j]+x;
        }
    }
    /*
    rep(i,n){
        rep(j,m)cout<<Block[i+1][j+1]<<" ";
        cout<<endl;
    }
    */
    rep(i,n-b){
        rep(j,m-a){
            int x=j+a,y=i+b,area=Block[y][x]+Block[i][j]-Block[y][j]-Block[i][x];
            chmin(ans,area);
            //cout<<i<<" "<<j<<" area:"<<area<<endl;
            //cout<<"y:"<<i+b+1<<" x:"<<j+a+1<<endl;
            //cout<<"z:"<<i+1<<" w:"<<j+1<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
二次元累積和を用いる。
計算量はO(N**2)

いろいろバグらせたけどまあ大丈夫かな
-1は大きな値にして計算に考慮させないようにする。

7 6
3 2
26 29 84 15 -1 1 71
45 14 38 91 62 77 35
68 -1 -1 90 63 56 70
31 2 4 74 72 41 90
100 26 21 -1 44 72 60
71 4 40 93 48 -1 50

*/