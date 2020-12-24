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
    while(1){
        int n,m,np=0;
        cin>>n>>m;
        if(n==0&&m==0)break;
        vi mas(n),saikoro(m);
        rep(i,n){
            cin>>mas[i];
        }
        rep(i,m){
            cin>>saikoro[i];
        }
        rep(i,m){
            //cout<<"p:"<<np<<endl;
            int p=np;
            np+=saikoro[i];
            //cout<<"sp:"<<np<<" "<<saikoro[i]<<endl;
            if(np>=n-1){
                cout<<i+1<<endl;
                break;
            }
            np+=mas[np];
            //cout<<"np:"<<np<<" "<<mas[np]<<endl;
            if(np>=n-1){
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}