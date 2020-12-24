//解説Submit

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e7+7;
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
    int n,k;
    cin>>n>>k;
    vii fares(n+2,vi(n+2,INF));
    rep(i,n)fares[i][i]=0;
    rep(i,k){
        int x;
        cin>>x;
        if(x){
            int c,d,e;
            cin>>c>>d>>e;
            c--,d--;
            chmin(fares[c][d],e);
            chmin(fares[d][c],e);
            rep(j,n){
                rep(k,n){
                    int total1=fares[k][c]+fares[c][d]+fares[d][j];
                    int total2=fares[j][d]+fares[d][c]+fares[c][k];
                    //cout<<"total:"<<total1<<" "<<j<<" "<<k<<endl;
                    chmin(fares[k][j],min(total1,total2));
                    chmin(fares[j][k],min(total1,total2));
                }
            }
        }else{
            int a,b;
            cin>>a>>b;
            a--,b--;
            if(fares[a][b]>=INF)cout<<-1<<endl;
            else cout<<fares[a][b]<<endl;
        }
    }
    return 0;
}

/*
航路の追加の時に料金を計算し直す。
UFで繋がっているかどうかを把握、
前計算しておいた料金を提示する。
*/