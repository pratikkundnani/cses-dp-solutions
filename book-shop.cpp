#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vvi vector<vector<int>>
int n,x;
int rec(int cap,vi& price, vi& pages) {
    // dp[i][j] = max pages we can buy with i items and j rupees
    vvi dp(n+1,vi(cap+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= cap; ++j) {
            if(price[i - 1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-price[i-1]] + pages[i-1],dp[i-1][j]);
        }
    }
    return dp[n][x];
}
void solve() {
    cin >> n >> x;// x = capacity;
    vi price(n); for (int i = 0; i < n; ++i) cin >> price[i];
    vi pages(n); for (int i = 0; i < n; ++i) cin >> pages[i];
    cout << rec(x, price, pages) << endl;
 
}
int32_t main() {
    solve();
}
