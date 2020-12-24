//解説Submit
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
    int n,right=0,leftColor,ibColor;
    cin>>n>>leftColor;
    ibColor=leftColor;
    vi a(n,0);
    a[right]=1;
    rep(i,n-1){
        int stone;
        cin>>stone;
        if(stone==ibColor){
            a[right]++;
        }else if(i%2==0){
            if(right==0){
                //今までおいたの全部ひっくり返せる時
                //今までの分に+1して色を変えるだけでいい。
                a[right]++;
                leftColor=stone;
            }else{
                //ひっくり返すのはa[right]
                //その前の区間(なぜなら色が同じなので)と足す
                a[right-1]+=a[right]+1;
                //色の層が一つ消えたからデクリメント
                right--;
            }
        }else{
            right++;
            a[right]=1;
        }
        ibColor=stone;
    }
    int sum=0;
    rep(i,right+1){
        if(i%2==leftColor)sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
/*
配列の各要素ごとに色を変えて、保持するのは連続の数
圧縮の意味がわかった
rightまでの中から計算する。
rightまでに有効な値を格納しているため。
*/