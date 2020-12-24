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
    int n;
    ll t=pow(10,10);
    string s,check="110";
    cin>>n>>s;
    if(s=="1"){
        cout<<2*t<<endl;
        return 0;
    }
    else if(s=="11"){
        cout<<t<<endl;
        return 0;
    }
    bool isOK=false;
    rep(i,3){
        int x=0,cnt=i;
        rep(i,n){
            if(s[i]==check[cnt]){
                x++;
            }
            cnt=(cnt+1)%3;
        }
        if(x==n){
            isOK=true;
            break;
        }
        //cout<<x<<endl;
    }
    if(!isOK){
        cout<<0<<endl;
        return 0;
    }
    int k=0;
    /*
    文字列が正しいのならば、
    0は規則的に並んでいる。ので、0の数がわかれば110の数もわかる
    重なりもあるので、10**10からkを引くことで答えがわかる？
    */
    rep(i,n)if(s[i]=='0')k++;
    if(s[n-1]=='0')cout<<t-k+1<<endl;
    else cout<<t-k<<endl;
    return 0;
}
/*
文字列sがありえるかを判定する。
sの初め3文字によって場合分け
その結果によって10**10を減算する。

110
101
011

TはいつでもSの要件を満たした連続部分列なのか……？
sが正しい文字列かどうか判定する処理を間違えていた。
*/