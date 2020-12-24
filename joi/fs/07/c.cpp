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

bool isOK(int a){
    int r=0,l=5000;
    if(r<=a&&a<=l)return true;
    return false;
}

int main(){
    int n,ans=0;
    cin>>n;
    vector<pair<int,int>> point(n);
    vector<vector<bool>> mp(5002,vector<bool>(5002,false));
    rep(i,n){
        int x,y;
        cin>>x>>y;
        point[i]={x,y};
        mp[y][x]=true;
    }
    rep(i,n){
        REP(j,i+1,n){
            auto a=point[i],b=point[j];
            //cout<<"i,j "<<i<<" "<<j<<endl;
            //cout<<a.first<<" "<<a.second<<endl;
            //cout<<b.first<<" "<<b.second<<endl;
            pair<int,int> c,d;
            int p=b.first-a.first,q=b.second-a.second;
            c={a.first+q,a.second-p},d={b.first+q,b.second-p};
            //cout<<"p,q "<<p<<" "<<q<<endl;
            //cout<<"c:"<<c.first<<" "<<c.second<<endl<<"d:"<<d.first<<" "<<d.second<<endl;
            //cout<<mp[c]<<" "<<mp[d]<<endl;
            if(!(isOK(c.first)&&(isOK(c.second))&&(isOK(d.first))&&(isOK(d.second))))continue;
            if(mp[c.second][c.first]&&mp[d.second][d.first]){
                ans=max(ans,p*p+q*q);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
2点を選ぶことで正方形の一辺が求まる。
p=x1-x2の差をyに、q=y1-y2の差をxに足すと、選んだ点とその点に接した点の座標が求まる。
10
9 4
4 3
1 1
4 2
2 4
5 8
4 0
5 3
0 5
5 2

i=2,j=6
3,-1


1+3=4,1+1=2


*/