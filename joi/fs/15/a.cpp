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
    ll n,m,sum=0;
    cin>>n>>m;
    vector<ll> p(m),imos(n+1,0);
    vector<vector<ll>> rail(n,vector<ll>(3));
    rep(i,m)cin>>p[i];
    rep(i,n-1){
        rep(j,3){
            ll x;
            cin>>x;
            rail[i][j]=x;
        }
    }
    rep(i,m-1){
        ll r=max(p[i],p[i+1]),l=min(p[i],p[i+1]);
        imos[r]--;
        imos[l]++;
    }
    rep(i,n)imos[i+1]+=imos[i];
    //for(auto x:imos)cout<<x<<" ";
    //cout<<endl;
    rep(i,n-1){
        //cout<<imos[i+1]*rail[i][0]<<" "<<imos[i+1]*rail[i][1]+rail[i][2]<<endl;
        sum+=min(imos[i+1]*rail[i][0],imos[i+1]*rail[i][1]+rail[i][2]);
    }
    cout<<sum<<endl;
    return 0;
}

/*
区間が何回出てくるか、和を取る。
その和にを区間和と呼ぶ
区間和の切符とICでの最小を求める。
これら区間の総和が答え。
imos法だっけな。
*/