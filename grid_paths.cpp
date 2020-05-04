//Author: kaiyu
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
#define sz(x) ((long long)(x).size())
#define mod             1000000007 //1e9+7

#define  fio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int MAXN = 1 * 1000000 + 10; // 1e6


int ways(int x, int y, vector<vector<ll>> & dp, vector<vector<char>> & grid) {
    if(grid[x][y] == '*') {
        return dp[x][y] = 0;
    }
    if(x == 0 && y == 0) {
        return 1;
    }
    else if(x==0) {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        return dp[x][y] = ways(x,y-1,dp,grid)%mod;
    }
    else if(y==0) {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        return dp[x][y] = ways(x-1,y,dp,grid)%mod;
    }
    else {
        if(dp[x][y] != -1) {
            return dp[x][y];
        }
        return dp[x][y] = (ways(x-1,y,dp,grid) + ways(x,y-1,dp,grid)) % mod;
    }

}
int32_t main() {
    fio
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
    n--;
    ways(n,n,dp,grid);
    cout << dp[n][n];

    return 0;

}
