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
    int h,w;
    ll cnt=0;
    cin>>h>>w;
    vector<string> s(h);
    vii orbsum(h+1,vi(w+1,0)),ingotsum(h+1,vi(w+1,0));
    queue<pair<int,int>>que;
    rep(i,h)cin>>s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='J'){
                que.emplace(i,j);
            }
            if(s[i][j]=='O'){
                orbsum[i][j+1]=orbsum[i][j]+1;
            }else orbsum[i][j+1]=orbsum[i][j];
            if(s[i][j]=='I'){
                ingotsum[i+1][j]=ingotsum[i][j]+1;
            }else ingotsum[i+1][j]=ingotsum[i][j];
        }
    }
    while(!que.empty()){
        ll y=que.front().first,x=que.front().second;
        que.pop();
        ll orb=orbsum[y][w]-orbsum[y][x],ingot=ingotsum[h][x]-ingotsum[y][x];
        cnt+=max(ll(0),orb*ingot);
    }
    cout<<cnt<<endl;
    return 0;
}
/*
宝石の
lはjよりも大きいことなので、右側にオーブが
kはiよりも大きいことなので、下側に金塊が
あることが条件
*/