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

vector<string> check={"open","incorrect","correct"};

int main(){
    int n,m,t,x,y;
    cin>>n>>m>>t>>x>>y;
    vii open(n,vi(m,-1)),wa(n,vi(m,0));
    vi point(m),ans(n,0);
    rep(i,m)cin>>point[i];
    rep(i,y){
        int a,b,c;
        string s;
        cin>>a>>b>>c>>s;
        b--,c--;
        if(s==check[0]){
            if(open[b][c]==-1)open[b][c]=a;
        }else if(s==check[1]){
            if(open[b][c]!=-1)wa[b][c]++;
        }else{
            if(open[b][c]!=INF){
                ans[b]+=max(point[c]-(a-open[b][c])-120*wa[b][c],x);
                open[b][c]=INF;
            }
        }
    }
    for(auto HavePoint:ans)cout<<HavePoint<<endl;
    return 0;
}