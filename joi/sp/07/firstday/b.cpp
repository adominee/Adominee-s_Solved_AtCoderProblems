/*
解説Submit
勉強させていただいた記事
https://mudkip-pokemon.blog.ss-blog.jp/2012-02-17-1
理解しようとしている中で、n=32の時、10と返されるが実際mは8なことに気づいた。
下の方のコードで試すと8と返ってくる。
手元の計算でも8
自信ないけど多分誤回答なんじゃないかな……
何が間違っているのかを指摘する実力も時間もないので暇があったら頑張って証明しよう………

https://lattemalta.hatenablog.jp/entry/2015/09/16/032833
素因数分解という当たりはついたが、そこから先に進めず。

latte0119氏の記事で勉強させていただいた。
どうしてMをpでひたすら割ればいいのかはM!のそれぞれの数について、pが何回かけられているかを層状に考えるとわかりやすい？

二分探索のいい勉強になったような、数学のいい勉強になったような。

例えばM=8,p=2
8 7 6 5 4 3 2 1
2   2   2   2   一層
2       2       二層
2               三層

上の感じのようなグラフ。
8/2=4   一層の2の数と同値
8/4　二層の2の数と同値
8/8　これも三層の2の数と同値
まあ、8までに2は何回登場するか？4
8までに4は何回登場するか？ 2
8までに8は何回登場するか？ 1
割ってるので4は2,8は2になっているから
Mをpでひたすら割ってるのか。
数学とかで習った気もしなくはない。

二分探索は境界値探索の必須手法


素因数分解して、素因数*素因数の指数個で答えが出るのはなるほどとしか言いようがない。
素因数が指数個ある。例えば2が5個ある場合を考える。
2**5=32
10! 5 9 4 7 3 5 2 3 1 1
2 4 6 8

12 2**2 3,
2 4
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

bool isOK(int mid,int n,int m){
    int sum=0;
    while(mid){
        sum+=mid/n;
        mid/=n;
    }
    if(sum>=m)return true;
    return false;
}

map<int,int>mp;
int nibu(int n,int m){
    //求めたいのはNで割れるM
    //求め方は上のやつ
    int ng=0,ok=1e8;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(isOK(mid,n,m))ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=2;i*i<n;i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n!=1)mp[n]++;
    for(auto x:mp){
        chmax(ans,nibu(x.first,x.second));
    }
    cout<<ans<<endl;
    return 0;
}

/*
因数分解をする
mの階乗がnで割り切れるとは
mにnの因数が含まれていること。
ある数までにあるその因数の個数は、その因数である数を割った結果の階乗
*/