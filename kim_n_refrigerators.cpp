#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int manhattan(pair<int, int> x, pair<int, int> y) {
    return abs(x.first-y.first)+abs(x.second-y.second);
}
int modTSP(int mask, int curr, vector<vector<int>> &distance, vector<vector<int>> &dp, int n, int home) {
    if(mask==(1<<n-1)-1) return distance[curr][home];
    if(dp[mask][curr]!=-1) return dp[mask][curr];
    int ans = INT_MAX;
    for(int i = 0; i < n-1; i++) {
        if((mask&(1<<i)) == 0) {
            int newAns = distance[curr][i]+modTSP(mask|(1<<i), i, distance, dp, n, home);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][curr] = ans;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tc = 10;
    for(int t = 1; t <= tc; t++) {
        int n;
        cin >> n;
        n+=2;
        vector<vector<int>> distance(n, vector<int>(n));
        vector<vector<int>> dp(1<<n, vector<int>(n, -1));
        vector<pair<int, int>> location(n);
        cin >> location[0].first >> location[0].second >> location[n-1].first >> location[n-1].second;
        for(int i = 1; i < n-1; i++) {
            cin >> location[i].first >> location[i].second;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                distance[i][j] = manhattan(location[i], location[j]);
            }
        }
        cout << "# " << t << " " << modTSP(1, 0, distance, dp, n, n-1) << endl; 
    }
    return 0;
}
