/**
 *  解説AC
 * 勉強させていただいた記事
 *https://drken1215.hatenablog.com/entry/2020/11/07/044400
 *  
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

int main(){
    string s;
    vi a(26,0);
    cin>>s;
    if(s.size()==26){
        string t;
        for(int i=25;i>=0;i--){
            t=s.substr(0,i+1);
            a[s[i]-'a']++;
            rep(j,26){
                if(a[j]&&j>t[i]-'a'){
                    t.pop_back();
                    t.pb(j+'a');
                    cout<<t<<endl;
                    return 0;
                }
            }
        }
        cout<<-1<<endl;
        return 0;
    }
    rep(i,s.size()){
        a[s[i]-'a']++;
    }
    int cnt=0;
    rep(i,26){
        if(!a[i]){
            s.pb('a'+i);
            break;
        }
        cnt++;
    }
    cout<<s<<endl;
    return 0;
}

//a=97,z=122
//abcdefghijklmnopqrstuvwzyx