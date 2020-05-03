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

const int MAXN = 5 * 1000000 + 10; // 1e6

#define int long
ll dp[MAXN];
void ddp(int n,vector<int> & sum) {

    dp[0] = 0;
    
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j < sz(sum); ++j) {
            if(i-sum[j] >=0)
            dp[i] = min(dp[i],1+dp[i-sum[j]]);
        }
    }

}

int32_t main() {
    fio
    int n,x;
    cin >> x >> n;
    vector<int>sum(x);
    
    for (int i = 0; i <x; ++i) {
        cin >> sum[i];
    }
    
    for (int j = 0; j <=n; ++j) {
        dp[j]=INT_MAX;
    }
    
    ddp(n,sum);
    
    if(dp[n] == INT_MAX) cout << -1 << endl;
    else cout << dp[n] << endl;
}




