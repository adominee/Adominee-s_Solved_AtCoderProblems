/*
https://algoogle.hadrori.jp/joi/sc2011apples/
勉強させていただいた記事
りんごの濃さに対して、その後ろにBの区間を考えるのか……
Segtree初めてで理解ががが
むずすぎないか？

https://qiita.com/agate-pris/items/05948b7d33f3e88b8967
void update と int updateの二つがあったのでなぜ？と思ったら
有効なポインタを渡すとintの方も呼ばれる仕様らしい。
ポインタは*
参照渡しは&
でも、void updateでint updateを呼び出している感じがするな……
https://programming-place.net/ppp/contents/cpp/language/008.html#:~:text=C%2B%2B%20%E3%81%A7%E3%81%AF%E3%80%81%E4%BB%AE%E5%BC%95%E6%95%B0%E3%81%AE,%E3%81%B0%E3%81%AA%E3%82%8A%E3%81%BE%E3%81%9B%E3%82%93%E3%81%A7%E3%81%97%E3%81%9F%E3%80%82
関数オーバーロードというものでした。
記事によると、ポインタと参照渡しでオーバロードが出来るというものだった。

https://qiita.com/kkent030315/items/b702945be1be66f590c4#%E3%82%A2%E3%83%AD%E3%83%BC%E6%BC%94%E7%AE%97%E5%AD%90
v->r
の->はアロー演算子と呼ばれるもので、ポインタ変数に対して使うらしい。

segtreeの問題やってからの方がいいかもしれない。
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

struct segtree{
    struct node{
        int mval,l,r,added;
        node *par ,*left,*right;
        node():mval(0),l(0),r(0),added(0){}
        node(node *p,int l,int r):mval(0),l(l),r(r),added(0){
            par=p;
            left=right=NULL;
        }
    };
    int N;
    node *root;
    map<int,int>vs;
    segtree(){}
    segtree(int n){
        N=1;
        while(N<n)N*=2;
        root=new node (NULL,0,N);
    }
    
    void update(int a,int b,int x){
        vs[a]+=x;
        if(!vs[a])vs.erase(a);
        //関数オーバーロード
        update(a,min(b,N),x,root);
    }
    int update(int a,int b,int x,node *v){
        //v->r ポインタ変数へのアクセスに使う記法
        if(a>= v->r || b <= v->l) return v->mval;
        if(a<= v->l && v->r <=b){
            v->added +=x;
            v->mval +=x;
            return v->mval;
        }
        int m=(v->l+v->r)/2;
        if(v->left==NULL)v->left=new node(v,v->l,m);
        v->mval = updeate(a,b,x,v->left);
        if(v->right==NULL)v->right=new node(v,m,v->r);
        v->mval = max(v->mval,update(a,b,x,v->right));
        v->mval +=v->added;
        return v->mval;
    }
    void query(int x, int b) {
            int r = get_right(x, root);
            if(r < 0) {
                    cout << "NO" << endl;
                    return;
            }
            auto it = vs.upper_bound(r-1);
            it--;
            vector<int> ws;
            while(x--) {
                    while(!it->second) it--;
                    ws.push_back(it->first);
                    it->second--;
            }
            for(int i = (int)ws.size()-1; i >= 0; i--) {
                    cout << ws[i] << (i>0? " ": "");
                    update(ws[i],ws[i]+b+1,-1,root);
            } cout << endl;
    }
    int get_right(int x, node *v) {
            if(v->mval < x) return -1;
            x -= v->added;
            if(v->right != NULL and v->right->mval >= x) return get_right(x, v->right);
            if(v->left != NULL and v->left->mval >= x) return get_right(x, v->left);
            return v->r;
    }
};

int q,b,x;

void solve(){
    segtree st(1e9);
    char c;
    while(q--){
        cin>>c;
        if(c=='E')break;
        cin>>x;
        if(c=='A')st.update(x,x+b+1,1);
        else st.query(x.b);
    }
}

int main(){
    cin>>q>>b;
    solve();
    return 0;
}
/*
クエリ処理問題
mapでりんごを持つ
foreachで上からりんごを数え、ばらつきを計算。
*/