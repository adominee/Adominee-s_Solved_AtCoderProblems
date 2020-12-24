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
    int n,ans=0,m,index=1;
    string name;
    cin>>n>>name;
    m=name.size();
    map<char,int>mp;
    for(auto x:name){
        if(mp.find(x)==mp.end()){
            mp[x]=index;
            index++;
        }
    }
    rep(i,n){
        string s;
        cin>>s;
        rep(j,s.length()){
            bool isAns=false;
            if(s[j]==name[0]){
                rep(k,s.length()-j){
                    string b;
                    for(int o=0;j+o<s.length();o+=(k+1)){
                        b.pb(s[j+o]);
                        if(b.length()>=m)break;
                    }
                    //cout<<k<<":"<<b<<endl;
                    if(name==b){
                        ans++;
                        isAns=true;
                        break;
                    }
                }
            }
            if(isAns)break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
文字が文字列にあるかじゃなくて、文字列が文字列にあるか。
setは不可。
難しく考えすぎ。
*/