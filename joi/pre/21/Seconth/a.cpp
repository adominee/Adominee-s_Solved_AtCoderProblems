#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T,class Y> inline bool chmin(T& a, Y b) {if (a > b) {a = b;return true;}return false;}
template<class T,class Y> inline bool chmax(T& a, Y b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
template<class T,class Y>T LCM(T a,Y b){return (a*b)/GCD(a,b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    //0=right,1=left
    int  n,a,cnt=0,p=INF,d=1,right,left;
    ll ans=0;
    string s;
    cin>>n>>a>>s;
    a--;
    p=n-a;
    vi sharp={0};
    rep(i,n)if(s[i]=='#'){
        cnt++;
        if(i-a>=0&&p>i-a){
            chmin(p,i-a);
            right=cnt;
            //cout<<right<<" "<<i-a<<endl;
        }
        sharp.pb(i+1);
    }
    sharp.pb(n+1);
    if(cnt==0){
        cout<<0<<endl;
        return 0;
    }
    int len=sharp.size();
    ans+=p;
    if(p==n-a){
        right=len-1;
        left=len-2;
        p=sharp[right];
    }else{
        left=right-1;
        p=sharp[right];
        right++;
        cnt--;
    }
    //for(auto x:sharp)cout<<x<<" ";
    //cout<<endl;
    //cout<<"left:"<<left<<" right:"<<right<<" len:"<<len<<endl;
    while(cnt>0){
        if(d%2==0){
            //cout<<"p:"<<p<<" right:"<<sharp[right]<<endl;
            ans+=abs(p-sharp[right]);
            p=sharp[right];
            if(right<len-1){
                right++;
                cnt--;
            }
        }else{
            //cout<<"p:"<<p<<" left:"<<sharp[left]<<endl;
            ans+=abs(p-sharp[left]);
            p=sharp[left];
            if(left>0){
                left--;
                cnt--;
            }
        }
        //cout<<ans<<endl;
        d++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
区間を圧縮したい、
#の間を行き来する
aに最も近い#の場所を保存
二分探索で位置を割り出す？
左右どこまで飛んだかを記憶し、飛ぶたびにansに加算する
*/