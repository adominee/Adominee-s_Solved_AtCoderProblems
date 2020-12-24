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
    int n,m;
    unordered_map<int,bool> xmp,ymp;
    cin>>m;
    vector<pair<int,int>> sign,star;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        sign.pb({a,b});
    }
    int x=sign[0].first,y=sign[0].second;
    cin>>n;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        xmp[a]=true;
        ymp[b]=true;
        star.pb({a,b});
    }
    rep(i,n){
        int dfx=star[i].first-x,dfy=star[i].second-y;
        //cout<<dfx<<" "<<dfy<<endl;
        bool isOK=true;
        rep(j,m){
            if(xmp[sign[j].first+dfx]&&ymp[sign[j].second+dfy])continue;
            isOK=false;
            break;
        }
        if(isOK){
            cout<<dfx<<" "<<dfy<<endl;
            return 0;
        }
    }
    return 0;
}

/*
星座の一点を取り出し、写真の各星とのdiffを計算する。
diffを星座に足す。そこに星があればセーフなければアウト。
*/