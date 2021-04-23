#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
      
        if (it == dp.end()) { // Append it to the LIS
            dp.push_back(x);
        } else {
            *it = x; // It doesn't change the length of the LIS
        }
    }
    // DP vector isn't the LIS 
    cout << dp.size() << endl;
