/*
https://kagamiz.hatenablog.com/entry/2012/11/06/005615
勉強させていただいたコード
方針はあってたけどWAが取れなかった……

*はAよりも数が小さいので、配列参照でSegfaるので、Zの次、[を使うことに。
orderを操作ずみかを記録するためのものとしても使っている。
同じものがあったら区別できないので、文字ごとにそれを使ったかをk記録する必要があるので、
check配列が必要。
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

ll FactArr[100];

void Fact(){
    FactArr[0]=1;
    REP(i,1,25)FactArr[i]=FactArr[i-1]*i;
}

ll perm(string s,ll pos){
    ll l=s.length(),ret=FactArr[s.length()-pos];
    vi memo(33,0);
    rep(i,l){
        if(s[i]!='['){
            memo[s[i]-'A']++;
        }
    }
    rep(i,26){
        ret/=FactArr[memo[i]];
    }
    return ret;
}

int main(){
    string str,order;
    cin>>str;
    int n=str.length();
    Fact();
    order=str;
    sort(ALL(order));
    ll pos=0;
    rep(i,n){
        vector<bool> check(33,false);
        int j;
        for(j=0;j<n;j++){
            if(str[i]==order[j])break;
            if(check[order[j]-'A']==true||order[j]=='[')continue;
            char t=order[j];
            order[j]='[';
            pos+=perm(order,i+1);
            order[j]=t;
            check[order[j]-'A']=true;
        }
        order[j]='[';
    }
    cout<<pos+1<<endl;
    return 0;
}
/*
シミュレーションじゃ間に合わない。
与えられた文字列の先頭が出てくるまで、アナグラムの先頭を変える。
その時、カウンタにその文字を先頭として、何通り作れるかを足す。
文字列のi番目に対して、操作済みとしていく？
先頭の文字列を操作済みとしていくのはあり

OOIの時4になってしまい、カウントしすぎ？
長さが2の時、通りは二つだけ。
順列計算の時に、未ソートの配列を渡していたせいで、正しく同じものを含む順列にならなかった。
*/