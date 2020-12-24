/*
問題文はよく読もうね！
aがx軸、bがy軸だからね
南北にa,東西にbだからaがy,bがxじゃない。
南北"に"伸びているだからね。道路自体は縦。
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

int a,b;
int dfs(int x,int y,vii road){
    int w=0,z=0;
    if(x==b-1&&y==a-1)return 1;
    if(y+1<a&&road[y+1][x]!=1)w=dfs(x,y+1,road);
    if(x+1<b&&road[y][x+1]!=1)z=dfs(x+1,y,road);
    return w+z;
}

int main(){
    int n,ans=0;
    cin>>a>>b>>n;
    vii road(b,vi(a,0));
    rep(i,n){
        int x,y;
        cin>>x>>y;
        x--,y--;
        road[y][x]=1;
    }
    queue<pair<int,int>>que;
    que.push({0,0});
    while(!que.empty()){
        auto o=que.front();
        que.pop();
        int y=o.first,x=o.second;
        if(y==b-1&&x==a-1){
            ans++;
            continue;
        }
        if(y+1<b&&road[y+1][x]==0)que.push({y+1,x});
        if(x+1<a&&road[y][x+1]==0)que.push({y,x+1});
    }
    cout<<ans<<endl;
    return 0;
}