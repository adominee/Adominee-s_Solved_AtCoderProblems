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
    int h,w,cnt=0;
    cin>>h>>w;
    vector<string> a(h);
    rep(i,h)cin>>a[i];
    queue<tuple<int,int,int>> que;

    rep(i,h){
        rep(j,w)if(a[i][j]=='#')cnt++;
    }

    que.emplace(0,0,1);
    while(!que.empty()){
        auto z=que.front();
        que.pop();
        int x=get<1>(z),y=get<0>(z),dist=get<2>(z);
        rep(i,2){
            int nx=x+dx[i],ny=y+dy[i];
            if(ny>=h||nx>=w)continue;
            if(a[ny][nx]=='#'){
                que.emplace(ny,nx,dist+1);
                if(ny==h-1&&nx==w-1&&cnt==dist+1){
                    cout<<"Possible"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}
/*

*/