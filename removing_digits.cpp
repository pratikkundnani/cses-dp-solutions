//Author: kaiyu
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <iomanip>
#include <climits>
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
#define mod             1000000007 //1e9+7
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<int,int>
#define tt ll t;cin >> t;while(t--)
#define int3(x,y,z) ll x,y,z;cin >> x >> y >> z;
#define int2(x,y) ll x,y;cin >> x >>y;
#define int1(x) ll x;cin>>x;
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
ll power(ll a,ll b,ll m=mod){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


bool cmp(pair<string,int>p1,pair<string,int>p2) {
    return p1.ss > p2.ss;
}

const int MAXN = 1 * 1000000 + 10; // 1e6


void ddp(int n,vector<ll>&dp) {
    dp[0] = 0;
    
    for (int i = 0; i <= n; ++i) {
        for(char c : to_string(i)) {
            
            dp[i] = min(dp[i], dp[i-(c-'0')] + 1);
            
        }
    }
}
int32_t main() {
    fio
    int n;
    cin >> n;
    // dp[i] = Min operations to go from i to 0.
    vector<ll>dp(n+1,INT_MAX);
    ddp(n,dp);
    cout << dp[n];

    //Greedy solution is also correct.

    return 0;

}
