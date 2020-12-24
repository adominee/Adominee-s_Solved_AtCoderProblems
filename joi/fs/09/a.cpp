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

int solve(int x){
    if(x<3)return 0;
    return (x-1)/2;
}

int main(){
    int n,m,cnt=0,ans=0;
    string s;
    cin>>n>>m>>s;
    vi p(m,0);
    bool isI=false;
    if(s[0]=='I'){
        isI=true;
        cnt=1;
    }
    REP(i,1,m){
        if(s[i]=='I'){
            if(!isI)cnt++;
            else {
                int a=solve(cnt);
                p[a]++;
                cnt=1;
            }
            isI=true;
        }else{
            if(isI)cnt++;
            else {
                int a=solve(cnt);
                p[a]++;
                cnt=0;
            }
            isI=false;
        }
    }
    for(int i=m-1;i>=n;i--){
        p[i-1]+=p[i];
        if(p[i]==0)continue;
        ans+=p[i];
        //int a=i-n;
        //p[a]+=p[i];
    }
    cout<<ans<<endl;
    return 0;
}
/*
p2にはp1が2こ
p3にはp2が2こ p1が3こある
pの最大値を求めればnもわかるのでは？
Piをn+jとみなせば良い？
大きいやつは小さいやつとしても使えるのでは
*/