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
    int n,right=0,ans=0,total=0;
    cin>>n;
    vi lamp(n),arr(n+5,0);
    rep(i,n)cin>>lamp[i];
    arr[0]=1;
    rep(i,n-1){
        if(lamp[i+1]!=lamp[i])arr[right]++;
        else {
            arr[right+1]++;
            right++;
        }
    }
    //for(auto x:arr)cout<<x<<" ";
    //cout<<endl;
    rep(i,right+1){
        total+=arr[i];
        if(i>2)total-=arr[i-3];
        chmax(ans,total);
    }
    cout<<ans<<endl;
    return 0;
}

/*
電球が交互に点灯している連続部分列を把握、
相異なる連続部分列(部分列の先頭と末尾が異なる)が連続している場合、長い部分列を作ることが可能。
連続する二つのみしか出来ない
三つ連続していても、一括反転なのでだめ
連続部分列を操作するのはそれが交互に点灯している時のみ
二つだけかと思ったら、三つ足す？
連続部分列は交互になってる部分のみ、
列の長さが1だけならありだけど、
0 0 0 0 ならそれぞれが1扱いになるので、問題ない。
必ず列として不成立なのが1扱いになるので、列と列を繋げてくれる。
1ならありかな

9
0 1 0 0 1 0 0 1 0
について考えていたが、真ん中の010だけひっくり返せば良い 9
*/