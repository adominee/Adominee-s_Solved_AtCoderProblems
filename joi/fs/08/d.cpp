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

int m,n;

int dfs(int y,int x,int cnt,vector<vector<bool>> dist){
    dist[y][x]=true;
    int ans=0;
    /*
    cout<<endl;
    rep(i,n){
        rep(j,m)cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    cout<<cnt<<endl;
    */
    rep(i,4){
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||n<=ny||nx<0||m<=nx||dist[ny][nx]){
            chmax(ans,cnt);
            continue;
        }
        chmax(ans,dfs(ny,nx,cnt+1,dist));
    }
    return ans;
}

int main(){
    int ans=0;
    cin>>m>>n;
    vector<vector<bool>> dist(n,vector<bool>(m));
    rep(i,n)rep(j,m){
        bool x;
        cin>>x;
        dist[i][j] = !x;
    }
    rep(i,n){
        rep(j,m){
            if(dist[i][j])continue;
            chmax(ans,dfs(i,j,1,dist));
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
distを用いて訪れたかを記録
幅優先探索で最短経路を探索。
配列を残したいのでDFSかなぁ
distをそれぞれで持つ

DFSはvectorで
普通の配列だとポインタごとのようで、元が書き換えられていく。

distをいじる位置がダメだったみたい。
書いた通りに動いてくれなくて難しい……
難しい……

3 4
0 1 1
1 1 0
1 1 1
0 1 0

*/