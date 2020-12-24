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
    int n,m,ans,maxvote=0;
    cin>>n>>m;
    vi votes(n),mincost(n);
    rep(i,n){
        int a;
        cin>>a;
        if(i==0)mincost[i]=a;
        else mincost[i]=min(a,mincost[i-1]);
    }
    rep(i,m){
        int b;
        cin>>b;
        rep(j,n){
            if(b>=mincost[j]){
                votes[j]++;
                if(maxvote<votes[j]){
                    ans=j;
                    maxvote=votes[j];
                }
                break;
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}