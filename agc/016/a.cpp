/*
解説Submit
https://drken1215.hatenablog.com/entry/2020/04/09/020800
勉強させていただいたサイト

ランレングス圧縮と問題文の理解に時間がかかった……

一回の操作でi文字か、i+1文字かを何度も出来るのでシミュ
"操作では文字を消すことしか出来ない"
文字列xxxa
t'のiにi+1を選択したからと言ってt'のi+1文字目はi+2,i+3から選ばない
i+1,i+2から選ぶ
xxa
xxxを消すにはi+1を選択し続ける事が最適で、三回で消せる。
ランレングス圧縮を用いてxを数える。
ただ、この時数えるのはi,i+1ともにxであるようなx
i,i+1の操作の回数はこの条件を満たすxと同じである。
aと隣接しているxはi+1の操作を行うことでxを消すことが出来る。
そのため、(s[j]==c)^(s[i]==c)の条件となる。
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
    string s;
    cin>>s;
    int res=s.size();
    for(int k='a';k<='z';k++){
        char c=char(k);
        int tmp=0;
        for(int i=0;i<s.size();){
            int j=i;
            while(j<s.size()&&!(s[j]==c)^(s[i]==c))++j;
            /*
            jがs.sizeを超えないこと
            s[j]がcでない、またはs[i]がc
            同値ならば偽となるため、
            s[j]==c^s[i]==c
            はcのみ、xのみの時のみ偽、!がついて反転し、真となる。
            連続しているかの判定をしている。
            */
            if(s[i]!=c)chmax(tmp,j-i);
            /*
            j-iで区間の長さを求める。
            ランレングス圧縮なので、xを圧縮しているのもありそう。
            求めるのはcに変えられるxの総数であるためs[i]がcの時は除外
            */
            i=j;
        }
        chmin(res,tmp);
    }
    cout<<res<<endl;
    return 0;
}
/*
serval
sxxxxx
sxx
sx
s
*/