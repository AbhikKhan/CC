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
bool isPalindrome(string str, int i, int j){
    while(i < j){
        if(str[i] != str[j])return false;
        i++, j--;
    }
    return true;
}
void solve(){
    ll n;
    string str;
    cin>>n>>str;
    if(isPalindrome(str, 0, n - 1)){
        cout<<"YES\n";
        return;
    }
    string l = "", r = "";
    loopP(i,0,n){
        if(i % 2 == 0)l += str[i];
        else r += str[i];
    }
    sort(all(l));
    sort(all(r));
    
    if(l == r)cout<<"YES\n";
    else cout<<"NO\n";
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