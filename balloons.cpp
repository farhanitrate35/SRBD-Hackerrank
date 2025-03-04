#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstring>
#include <queue>

using namespace std;

int getMaxCost(int l, int r, vector<int> &balloons, bool considerNeighbors, vector<vector<int>> &dp) {
    if(l>r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    
    int maxScore = INT_MIN;
    for(int i = l; i <= r; i++) {
        int leftScore = getMaxCost(l, i-1, balloons, true, dp);
        int rightScore = getMaxCost(i+1, r, balloons, true, dp);
        int burstScore = (considerNeighbors)? balloons[l-1]*balloons[r+1] : balloons[i];
        maxScore = max(maxScore, leftScore+rightScore+burstScore);
    }

    dp[l][r] = maxScore;
    return dp[l][r];
}

int main() {
    int n;
    cin >> n;
    vector<int> balloons(n);
    for(int i = 0; i < n; i++) {
        cin >> balloons[i];
    } 
    
    balloons.insert(balloons.begin(), 1);
    balloons.push_back(1);

    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

    cout << getMaxCost(1, n, balloons, false, dp);
    return 0;
}