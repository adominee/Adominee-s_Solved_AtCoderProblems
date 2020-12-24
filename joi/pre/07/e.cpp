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
    int n,serialN=0;
    map<int,int>isExpexted,Category;
    rep(i,3){
        int x;
        cin>>x;
        REP(j,serialN,serialN+x)Category[j]=i;
        serialN+=x;
    }
    cin>>n;
    vi ans(serialN,2);
    vii insp(n,vi(3));
    rep(i,n){
        int pass;
        rep(j,3){
            cin>>insp[i][j];
            insp[i][j]--;
        }
        cin>>pass;
        if(pass){
            rep(j,3){
                ans[insp[i][j]]=1;
                isExpexted[insp[i][j]]=1;
            }
        }
    }
    rep(i,n){
        int cnt=0,broken;
        rep(j,3){
            if(isExpexted[insp[i][j]])cnt++;
            else broken=insp[i][j];
        }
        if(cnt==2){
            ans[broken]=0;
        }
    }
    for(auto x:ans)cout<<x<<endl;
    return 0;
}

/*
疑わしいパーツについて、試したパーツを記録して、試したパーツの白確を用いて判定する？
"一回の検査"で白確使ってないとだめだよね。
過去の検査で関係持ったとこに白があってそれが2Categoryであったら弾いてたけど不正確だね。
これじゃ別のが黒の可能性も排除できない。
*/