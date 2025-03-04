#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue> 
#include <set>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> dc = {-1, 0, 1};

int play(int r, int c, vector<vector<int>> grid, vector<vector<vector<vector<int>>>> dp, int safeRows, bool bombed) {
    if(r <= 0) return 0;
    if(dp[r][c][safeRows][bombed] != -1) return dp[r][c][safeRows][bombed];
    int maxCoin = 0;
    for(int i = 0; i < 3; i++) {
        int nr = r-1;
        int nc = c+dc[i];
        if(nr < 0 || nc < 0|| nc >= 5) continue;
        if(grid[nr][nc] == 2) {
            if(!bombed) {
                maxCoin = max(maxCoin, play(nr, nc, grid, dp, 5, true));
            }
            else {
                if(safeRows > 0) {
                    maxCoin = max(maxCoin, play(nr, nc, grid, dp, safeRows-1, bombed));
                }
                else {
                    continue;
                }
            }
        }
        else {
            int coins = grid[nr][nc];
            maxCoin = max(maxCoin, coins+play(nr, nc, grid, dp, safeRows-(safeRows>0), bombed));
        }
    }
    return dp[r][c][safeRows][bombed] = maxCoin;
}

int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t <=tc; t++) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(5, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(5, vector<vector<int>>(6, vector<int>(2, -1))));
        cout << "#" << t << " " << play(n, 2, grid, dp, 0, false) << endl;
    }
    return 0;
}