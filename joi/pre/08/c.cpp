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
    int n,board=0;
    bool turn=true;
    cin>>n;
    deque<int> taro,hanako;
    map<int,int>mp;
    rep(i,n){
        int x;
        cin>>x;
        taro.pb(x);
        mp[x]++;
    }
    sort(ALL(taro));
    REP(i,1,2*n+1){
        if(!mp[i])hanako.pb(i);
    }
    board=taro.front();
    taro.pop_front();
    while(!taro.empty()&&!hanako.empty()){
        bool isOK=false;
        if(turn){
            rep(i,hanako.size()){
                if(board<hanako[i]){
                    board=hanako[i];
                    hanako.erase(hanako.begin()+i);
                    isOK=true;
                    break;
                }
            }
        }else{
            rep(i,taro.size()){
                if(board<taro[i]){
                    board=taro[i];
                    taro.erase(taro.begin()+i);
                    isOK=true;
                    break;
                }
            }
        }
        if(!isOK)board=0;
        turn=!turn;
    }
    cout<<hanako.size()<<endl;
    cout<<taro.size()<<endl;
    return 0;
}

//priority_queはデフォルトだと降順。
/*
場のカード以下のカードをすぐにポイント換算するのではなく、墓地送りにして、出せるカードがなくなったら、場のカードをすて、墓地のカードを手札扱いにする。
その操作の後、どちらかの手札、及び墓地のカードが0ならば、終了し、墓地のカードを数える。

・墓地のカードを手札に戻す作業が書かれていなかった。
・墓地のカードは必ず手札に戻すので、手札を数える。

値反転させちゃいけないところで反転していた……

処理として、カードを全部墓地に送っていなくても相手でパスしてきた時、墓地から出さないといけないのでアウト
あー、墓地のカードも換算すれば良さそう。

5
1 2 3 4 5

1 ->6 -> pass
7 -> pass
8 -> pass
9 -> pass
10 -> pass

5
1 6 7 9 10
1->2->6->8->9->pass
taro 7 ->pass
taro 10 ->pass
hanako has 3 cards.

10
3 4 5 7 8 11 14 17 18 19
1 2 6 9 12 13 15 16 20
3->6-> 7->9-> 11->12-> 14->15-> 17->20-> pass
hanako 1->4-> 13->18-> pass
taro 5->16-> 19->pass
taro 8->pass
2しか残らない……

*/