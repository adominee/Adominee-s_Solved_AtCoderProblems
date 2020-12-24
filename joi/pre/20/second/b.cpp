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

using vi=vector<ll>;
using vii=vector<vi>;

#define REP(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse
#define ALL(a) (a).begin(),(a).end()
#define decimal(x) fixed<<setprecision(x)

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> str(n);
    rep(i,n){
        ll a,t;
        cin>>a>>t;
        str[i]={a,t};
    }
    sort(ALL(str));
    ll time=max(str[n-1].first,str[n-1].second);
    //cout<<time<<endl;
    for(int i=n-2;i>=0;i--){
        ll x=str[i+1].first-str[i].first,y=str[i].second-time;
        //cout<<x<<" "<<y<<endl;
        if(y<=x)time+=x;
        else time+=y;
    }
    time+=str[0].first;
    cout<<time<<endl;
    return 0;
}

/*
とりあえず最後まで行く
帰りの道中で実ってないやつ回収すればロスなし
もし、帰りで待たされても、待ってる間に他が実る。
そこを通るのは確実なので待ってて良い。
行って帰るまでの時間といちごを待つ時間
sortしないとじゃん
*/