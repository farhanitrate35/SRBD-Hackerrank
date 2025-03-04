#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
    
int tsp(int mask, int pos, vector<vector<int>> &dist, vector<vector<int>> &dp) {
    int n = dist.size();
    
    if(mask == (1<<n)-1) return dist[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    
    int minCost = INF;
    for(int nxt = 0; nxt < n; nxt++) {
        if(!(mask&(1<<nxt))) {
            int newCost = dist[pos][nxt] + tsp(mask|(1<<nxt), nxt, dist, dp);
            minCost = min(minCost, newCost);
        }
    }
    dp[mask][pos] = minCost;
    return dp[mask][pos];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, minCost = 0;
        cin >> n;
        vector<vector<int>> dist(n, vector<int>(n)) ;
        vector<vector<int>> dp(1<<n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }
        minCost = tsp(1, 0, dist, dp);
        cout << minCost << endl;
    }
    
    return 0;
}
