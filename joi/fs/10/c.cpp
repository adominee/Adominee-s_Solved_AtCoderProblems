/*
https://luzhiled.hatenablog.com/entry/2016/11/23/143106
勉強させていただいた解説
priority_queueを使って最大値から検証していく
隣に最大値があれば、解ける時間は最大値に足したものとなる。
なければ、L-Ai。
隣にあるかどうか判定するにはindexが必要なので、queueはpair<int,int>で保持
もし、つららが階段状にあるときはどう処理したらいいんだろうと考えていたが、
このやり方なら、もとまるのが容易に考えられる。
場所ごとにかかる時間を保存することで、重複をなくし、最大値を求められる。
t[i]にはL-a[j]が入って更新されていくので、問題が起きない。
あるつららの隣により大きいつららがあるのならば、更新処理が必要だが、なければ不要。
0初期化なので、特にこれといった処理なしに更新ができる。
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

//0に初期化された、つららが溶ける秒数を格納する配列。
int t[101010];

int main(){
    priority_queue<pair<int,int>> que;
    int n,l,ans=0;
    cin>>n>>l;
    rep(i,n){
        int x;
        cin>>x;
        que.emplace(x,i+1);
    }
    while(!que.empty()){
        auto v=que.top();
        que.pop();
        t[v.second]=max(t[v.second-1],t[v.second+1])+l-v.first;
        chmax(ans,t[v.second]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
sortは無理そう
O(N**2)はきつい

*/