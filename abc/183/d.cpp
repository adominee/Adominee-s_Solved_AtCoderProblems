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
    int n,w;
    cin>>n>>w;
    vector<ll> s(n),t(n),p(n),tt(3e5,0);
    rep(i,n){
        cin>>s[i]>>t[i]>>p[i];
        tt[s[i]]+=p[i];
        tt[t[i]]-=p[i];
    }
    if(tt[0]>w){
        cout<<"No"<<endl;
        return 0;
    }
    REP(i,1,2e5+5){
        tt[i]+=tt[i-1];
        if(tt[i]>w){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}