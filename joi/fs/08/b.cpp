/*
https://perogram.hateblo.jp/entry/2020/02/21/091907
解説Submit
LCSの更新処理を簡素にする
連続した区間でのみ更新されるようにする。
メモリが足りん……
LCSは想定解じゃなさそう？

公式解説に沿って実装
何個ずらせばいいかってなるほどとしか
公式解説ストンと入ってこないのがむずい
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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

int dp[4005][4005]={0};

int solve(string s,string t){
    int ans=0;
    rep(i,s.size()){
        string r=s.substr(i);
        int cnt=0;
        rep(j,min(t.size(),r.size())){
            if(r[j]==t[j])cnt++;
            else cnt=0;
            chmax(ans,cnt);
        }
    }
    return ans;
}

int main(){
    string s,t;
    cin>>s>>t;
    int ans=0;
    cout<<max(solve(s,t),solve(t,s))<<endl;
    return 0;
}