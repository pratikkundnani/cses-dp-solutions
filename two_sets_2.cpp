#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#pragma GCC optimize("O2")
#define CLR(s) memset(&s, 0, sizeof(s))
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a,x) for (auto& a : x)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
const int MOD = 1e9 + 7;
#define hmap        unordered_map
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll power(ll a,ll b,ll m=MOD){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}
double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
}
int dx[] = {-1,1,0,0,-1,1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};
const int MAXN = 2e5+ 10;
const ll inf = 1e18;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}
void read(vi & a) { for (int i = 0; i < sz(a); ++i) cin >> a[i];}
void solve() {
    int n;
    cin >> n;
    int sum = (n * (n + 1))/2;
    if(sum % 2) {
        cout << 0; return;
    }
    sum /= 2;
    int dp[n + 1][sum + 1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            int left = j - i;
            if(left >= 0) {
                (dp[i][j] += dp[i - 1][left]) %= MOD;
            }
        }
    }
    cout << dp[n-1][sum] << endl;
 
 
 
}
int32_t main() {
    fio
 
        solve();
}
 
