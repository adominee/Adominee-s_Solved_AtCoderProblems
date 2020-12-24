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
    int n,index=0,ans=INF;
    cin>>n;
    vi color(n),sec(n,0);
    cin>>color[0];
    sec[0]++;
    REP(i,1,n){
        int a;
        cin>>a;
        if(color[index]!=a){
            color[index+1]=a;
            sec[index+1]++;
            index++;
        }else sec[index]++;
    }
    //for(auto x:sec)cerr<<x<<" ";
    //cerr<<endl;
    rep(i,index+1){
        int up=i-1,down=i+1,cnt=n;
        vi csec=sec;
        if(i==0){
            csec[0]++;
            csec[1]--;
            if(index>1&&color[2]==color[0])csec[0]+=csec[2];
            if(csec[0]>3)chmin(ans,n-csec[0]);
        }
        else if(i==index){
            csec[index]++;
            csec[index-1]--;
            if(index>1&&color[index-2]==color[index])csec[index]+=csec[index-2];
            if(csec[index]>3)chmin(ans,n-csec[0]);
        }else{
            csec[i]++;
            csec[i-1]--;
            if(csec[i-1]==0){
                up--;
                if(i-2>=0&&color[i-2]==color[i]){
                    csec[i]+=csec[i-2];
                    csec[i-2]=0;
                    up--;
                }
            }
            if(csec[i]>3){
                cnt-=csec[i]--;
                while(up>=0&&down<=index&&color[up]==color[down]&&csec[up]+csec[down]>=4){
                    cnt-=(csec[up]+csec[down]);
                    up--,down++;
                }
                chmin(ans,cnt);
            }
        }
    }
    cout<<min(ans,n)<<endl;
    return 0;
}
/*
deque?
O(N**2)は大丈夫
シミュレートできそう。
消す位置を一箇所選ぶ。あーー、でも消すの大変だな。
区間和をとれば良さそう
色を変える時、色は隣接する色から選ぶ
色を変える時、考えればいいのは色が変わってる境目だけでは？
区間の真ん中を変えても意味がない。
区間ごとに考えて良さそう。
最初に考えたところが4以上にならなければ何も起きない
4以上になった時。その区間たちを無視したい。
indexとして、up,downで管理はあり？

4つ連結したかどうかが抜けていた><
*/