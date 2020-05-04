//Author: kaiyu
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
using namespace std;
typedef long long ll;
#define sz(x) ((long long)(x).size())
#define mod             1000000007 //1e9+7
#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

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
