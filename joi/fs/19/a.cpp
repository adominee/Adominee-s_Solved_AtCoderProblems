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

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    int h,w;
    ll sum=0;
    cin>>h>>w;
    vii orb(h,vi(w+1,0)),ingot(h+1,vi(w,0));
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='O')orb[i][j+1]=orb[i][j]+1;
            else orb[i][j+1]=orb[i][j];
        }
    }
    rep(j,w){
        rep(i,h){
            if(s[i][j]=='I')ingot[i+1][j]=ingot[i][j]+1;
            else ingot[i+1][j]=ingot[i][j];
        }
    }
    /*
    rep(i,h+1){
        rep(j,w){
            cout<<ingot[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='J'){
                int x=ingot[h][j]-ingot[i][j];
                int y=orb[i][w]-orb[i][j];
                //cout<<i<<" "<<ingot[h][j]<<" "<<ingot[i][j]<<endl;
                //cout<<x<<" "<<y<<endl;
                sum+=x*y;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
/*
列、行ごとに累積和を構築
i,jを決めて、i行にあるオーブとj列にあるインゴットの積の総和が答え。
インゴットはジュエルの下。
*/