//Author: kaiyu
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((long long)(x).size())
#define all(x)  x.begin(),x.end()
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define leastsigbit(x)     __builtin_ffs(x)
#define mod             1000000007
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<int,int>
#define vpii vector<pii>
#define tt ll tt;cin >> tt;while(tt--)
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
const double PI = acos(-1);
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
const int MAXN = 2e5+ 10;
 
#define int long long
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int editDistDP(string str1, string str2, int m, int n) {
    
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
                
                // If second string is empty, only option is to
                // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
                // If last characters are same, ignore last char
                // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
                // If the last character is different, consider all
                // possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                                   dp[i - 1][j], // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[m][n];
}
 
int32_t main() {
//#ifndef ONLINE_JUDGE
    //freopen("inp1.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
//#endif
    fio
    string a,b;
    cin >> a >> b;
    cout << editDistDP(a,b,sz(a),sz(b)) << endl;
 
 
    cerr << "[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
 
 
}
 
