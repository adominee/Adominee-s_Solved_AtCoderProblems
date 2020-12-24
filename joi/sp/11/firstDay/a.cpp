/*
https://qnighy.github.io/informatics-olympiad/joi2011-day1-banner-comment.html
勉強させていただいた記事
3色揃ってる部品の数え上げを考えるんですね……

その計算は全ての(x,y)について、(x,y)の色を黒としたとき(縦にある白)*(横にある灰)+(縦にある灰)*(横にある白)の和を各色について求めた総和
これが部品の条件を満たすものだからなるほど
総和は重複があるので2で割る。
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

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll h,w,ans=0;
    cin>>h>>w;
    vii pole(h,vi(w));
    vi wc(h,0),gc(h,0),wr(w,0),gr(w,0),bc(h,0),br(w,0);
    rep(i,h)rep(j,w){
        cin>>pole[i][j];
        if(pole[i][j]==0){
            bc[i]++,br[j]++;
        }
        else if(pole[i][j]==1){
            gc[i]++,gr[j]++;
        }else{
            wc[i]++,wr[j]++;
        }
    }
    rep(i,h){
        rep(j,w){
            if(!pole[i][j]){
                ans+=(gc[i]*wr[j])+(wc[i]*gr[j]);
            }else if(pole[i][j]==1){
                ans+=(wc[i]*br[j])+(bc[i]*wr[j]);
            }else{
                ans+=(bc[i]*gr[j])+(gc[i]*br[j]);
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
/*
2点を選んで全探索
他の2点は平行でなければならないという条件からすぐきまる。

3 4
0 1 0 2
1 2 0 1
0 0 2 1

*/