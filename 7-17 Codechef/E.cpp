#include<bits/stdc++.h>
using namespace std;

#define speed_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double

#define vt vector
#define pb push_back

#define loopP(x,s,e) for(ll x = s; x< e; ++x)
#define loopN(x,s,e) for(ll x = s; x> e; --x)
#define loopA(x,e) for(auto x: e)
#define loopIt(x,e) for(auto x = e.begin(); x != e.end(); x++)


#define all(x) (x).begin(), (x).end()
#define fact(n) tgamma(n + 1)


/* Trie */
struct Trie{
    bool isPresent;
    Trie *next[26];

    Trie(){
        memset(next, 0, sizeof(next));
        isPresent = false;
    }
};

/* Segment Tree */


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

/**************************************************************************************/
void solve(){
    ll n;
    cin>>n;
    string A, B;
    cin>>A>>B;
    if(A == B){
        cout<<"YES\n";
        return;
    }

    ll o = 0;
    while(o < n && A[o] != '1')o++;
    if(o == n){
        cout<<"NO\n";
        return;
    }
    if((A == "01" && B == "10") || (A == "10" && B == "01" )){
        cout<<"NO\n";
        return;
    }
    ll m = 0, k = 0;
    loopA(c,B){
        if(c == '0'){
            m++;
            k = 0;
        }
        else{
            k++;
            m = 0;
        }
        if(m > 1 || k > 1){    
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
}

int main(){
    speed_;
    ll t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    
    return 0;
}