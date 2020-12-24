/*
https://algoogle.hadrori.jp/joi/sc2008origami/
勉強させていただいたサイト
座標圧縮のようにやる。
map使って大丈夫らしい。
計算量の把握をミスった……

mapの要素参照の計算量
最悪で20*5000なので、log 1e5=5となる
実質O(1)なので高速

全体の計算量
O(N*20*20)<O(2e6)
十分高速
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

using vi=vector<int>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    map<pair<int,int>,int>mp;
    int n,a,b,c=0,area=0;
    cin>>n>>a>>b;
    rep(i,n){
        int p,q,r,s;
        cin>>p>>q>>r>>s;
        REP(j,q,s+1){
            REP(k,p,r+1){
                int cnt= ++mp[{j,k}];
                if(cnt>c){
                    c=cnt;
                    area=0;
                }
                if(cnt==c)area++;
            }
        }
    }
    cout<<c<<endl;
    cout<<area<<endl;
    return 0;
}
/*
台紙の縦と横を表す配列使い
これだと横の間隔は20以下だが、縦の間隔が20以上でだめということが考えられる。
*/