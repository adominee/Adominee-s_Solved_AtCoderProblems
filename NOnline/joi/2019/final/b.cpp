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
    int n,m,mv=0,mc=0,cnt=0;
    cin>>n>>m;
    vector<pair<int,int>> sv(n);
    vi c(m),s(n),v(n);
    rep(i,n){
        int x,y;
        cin>>x>>y;
        sv[i]={x,y};
    }
    rep(i,m){
        int x;
        cin>>x;
        c[i]=x;
    }
    sort(ALL(sv));
    sort(ALL(c));
    rep(i,n){
        s[i]=sv[i].first;
        v[i]=sv[i].second;
    }
    
    rep(i,m){
        int itr=lower_bound(ALL(s),c[i])-s.begin()-1;
        while(itr>=0){
            if(v[itr]>=mv){
                mv=v[itr];
                cnt++;
                break;
            }
            itr--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
絵画のサイズと価値をサイズ基準でソート
額縁をソート
額縁の小さい方から、二分探索で入る中で1番大きい絵を探索。
itr--して、入ったら入れる。
*/