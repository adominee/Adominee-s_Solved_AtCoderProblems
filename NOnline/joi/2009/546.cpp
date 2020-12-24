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
        int n,k;
        cin>>n>>k;
        if(!n&&!k)break;
        vi a(n);
        rep(i,n){
            cin>>a[i];
        }
        set<int> s;
        for(int bit=0;bit<(1<<n);bit++){
            vi b;
            for(int i=0;i<n;i++){
                if(bit&(1<<i))b.pb(a[i]);
            }
            if(b.size()!=k)continue;
            sort(ALL(b));
            do{
                int c=0;
                for(auto x:b){
                    if(x>9)c=c*100+x;
                    else c=c*10+x;
                }
                //cout<<"c:"<<c<<endl;
                s.insert(c);
            }while(next_permutation(ALL(b)));
        }
        cout<<s.size()<<endl;
    }
    return 0;
}