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
    int m,n,k;
    cin>>m>>n>>k;
    vector<string>s(m);
    vii jungle(m+1,vi(n+1,0)),ocean(m+1,vi(n+1,0)),ice(m+1,vi(n+1,0));
    rep(i,m)cin>>s[i];
    rep(i,m){
        rep(j,n){
            if(s[i][j]=='J'){
                jungle[i+1][j+1]=jungle[i+1][j]+jungle[i][j+1]-jungle[i][j]+1;
                ocean[i+1][j+1]=ocean[i+1][j]+ocean[i][j+1]-ocean[i][j];
                ice[i+1][j+1]=ice[i+1][j]+ice[i][j+1]-ice[i][j];
            }else if(s[i][j]=='O'){
                jungle[i+1][j+1]=jungle[i+1][j]+jungle[i][j+1]-jungle[i][j];
                ocean[i+1][j+1]=ocean[i+1][j]+ocean[i][j+1]-ocean[i][j]+1;
                ice[i+1][j+1]=ice[i+1][j]+ice[i][j+1]-ice[i][j];
            }else{
                jungle[i+1][j+1]=jungle[i+1][j]+jungle[i][j+1]-jungle[i][j];
                ocean[i+1][j+1]=ocean[i+1][j]+ocean[i][j+1]-ocean[i][j];
                ice[i+1][j+1]=ice[i+1][j]+ice[i][j+1]-ice[i][j]+1;
            }
        }
    }
    rep(i,k){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vi ans(3);
        a--,b--;
        ans[0]=jungle[c][d]-jungle[a][d]-jungle[c][b]+jungle[a][b];
        ans[1]=ocean[c][d]-ocean[a][d]-ocean[c][b]+ocean[a][b];
        ans[2]=ice[c][d]-ice[a][d]-ice[c][b]+ice[a][b];
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    }
    return 0;
}
/*
for(auto x:ans)cout<<x<<" ";
とやっていたので、
a b c <-
空白がcの後ろにあり、WAってしまった。
楽しようとしすぎるのも考えもの？
*/