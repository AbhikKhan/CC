#include<bits/stdc++.h>
using namespace std;

#define speed_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double

#define vt vector
#define pb push_back
#define F first
#define S second

#define loopP(x,s,e) for(ll x = s; x< e; ++x)
#define loopN(x,s,e) for(ll x = s; x> e; --x)
#define loopA(x,e) for(auto &x: e)
#define loopIt(x,e) for(auto x = e.begin(); x != e.end(); x++)


#define all(x) (x).begin(), (x).end()
#define fact(n) tgamma(n + 1)

/* Declaration */
ll gcd(ll a,ll b);
ll lcm(ll a,ll b);
double pw(double x, int n);
bool isPrime(ll n);

/* Trie */
struct Trie{
    bool isPresent;
    Trie *next[26];

    Trie(){
        memset(next, 0, sizeof(next));
        isPresent = false;
    }
};

/* Inputs */
template <typename T> /* vector */
istream& operator>>(istream &istream, vt<T> &X){
    loopA(x,X)
        cin>>x;
    
    return istream;
}
template <typename U, typename V> /* pair */
istream& operator>>(istream &istream, pair<U,V> &X){
    cin>>X.F>>X.S;
    return istream;
}

/* Outputs */
template <typename T> /* vector */
ostream& operator<<(ostream &ostream, const vt<T> &X){
    loopA(x,X)cout<<x<<" ";
    return ostream;
}
template <typename U, typename V> /* pair */
ostream& operator<<(ostream &ostream, const pair<U,V> &X){
    cout<<X.F<<" "<<X.S;
    return ostream;
}

/**************************************************************************************/

class SegmentTree{
public:
    vt<ll>seg;
    ll s;

    SegmentTree(ll n){
        s = n;
        seg.resize(4 * s + 1);
    }

    void build(ll ind, ll low, ll high, vt<ll>& nums){
        if(low == high){
            if(low != s - 1)seg[ind] = (nums[low] <= nums[low + 1]? 0: nums[low] - nums[low + 1]);
            else seg[ind] = 0;
            return;
        }
        ll mid = low + (high - low)/ 2;
        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];   
    }
    
    ll solve(ll l, ll r, ll ind, ll low, ll high) {
        if(low >= l && high <= r)return seg[ind];
        if(l > high || r < low)return 0;
        
        ll mid = low + (high - low)/ 2;
        return solve(l, r, 2 * ind + 1, low, mid) + solve(l, r, 2 * ind + 2, mid + 1, high);
    }
};

/*************************************************************************************/

void solve(){
    ll n, t;
    cin>>n>>t;
    vt<ll> heights(n);
    cin>>heights;

    SegmentTree st1(n), st2(n);

    st1.build(0, 0, n - 1, heights);
    reverse(all(heights));
    st2.build(0, 0, n - 1, heights);

    while(t--){
        ll s, e;
        cin>>s>>e;

        s--, e--;
        if(e > s){
            cout<<st1.solve(s, e - 1, 0, 0, n - 1);
        }
        else{
            e = n - 1 - e;
            s = n - 1 - s;
            cout<<st2.solve(s, e - 1, 0, 0, n - 1);
        }
        cout<<endl;
    }
}

int main(){
    speed_;
    ll t = 1;
    // cin>>t;
    while (t--)solve();
    return 0;
}

/* Functions */
ll gcd(ll a,ll b){
    if(a == 0)return b;
    return gcd(b % a, a);
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
double pw(double x, int n) {
    if(n == 0)return 1;
    if(n == 1)return x;
    double k = pw(x, abs(n/2));
    k = (n % 2 == 0?1: x) * k * k;
    return n> 0? k: 1/ k;
}
bool isPrime(ll n){ 
    if (n <= 1)return false;
    if (n <= 3)return true;

    if (n % 2 == 0 || n % 3 == 0)return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)return false;

    return true;
}