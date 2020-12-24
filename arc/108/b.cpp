/*
解説AC
両端キューを使って文字列sを切り取っていくのはわかったけど、
fofofoxxx
のケースに対応できなかった。
切り取った文字列tの末3つを見ればいいんだね……
fofofox->fofo
fofox->fo
fox->0
0って感じになる。
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

map<int,int> mp;

int main(){
    mp['f']=1;
    mp['o']=2;
    mp['x']=3;
    int n;
    string s;
    cin>>n>>s;
    deque<char> que(s.begin(),s.end());
    deque<int> x;
    while(!que.empty()){
        char c=que.front();
        que.pop_front();
        x.push_back(mp[c]);
        int m=x.size();
        while(m>=3&&x[m-1]==3&&x[m-2]==2&&x[m-3]==1){
            n-=3;
            x.erase(x.end()-3,x.end());
            m=x.size();
        }
        //rep(i,m)cout<<x[i]<<" ";
        //cout<<endl;
    }
    cout<<n<<endl;
    return 0;
}