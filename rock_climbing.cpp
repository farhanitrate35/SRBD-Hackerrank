#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> dc = {-1, 0, 1};
bool isValid(int r, int c, vector<vector<int>> rocks) {
    int n = rocks.size();
    int m = rocks[0].size();
    if(r<0||r>=n||c<0||c>=m||rocks[r][c]==0) return false;
    return true;
}
int findLevel(vector<vector<int>> &rocks) {
    int n = rocks.size();
    int m = rocks[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> level(n, vector<int>(m, INT_MAX));
    level[n-1][0] = 0;
    pq.push({0, {n-1, 0}});
    while(!pq.empty()) {
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        int currLevel = pq.top().first;
        pq.pop();
        if(rocks[r][c] == 3) return currLevel;
        for(int i = 0; i < 3; i++) {
            int nc = c+dc[i];
            if(isValid(r, nc, rocks)) {
                if(level[r][nc] > currLevel) {
                    level[r][nc] = currLevel;
                    pq.push({currLevel, {r, nc}});
                }
            }
        }
        for(int nr = 0; nr < n; nr++) {
            if(nr != r && isValid(nr, c, rocks)) {
                if(level[nr][c] > currLevel) {
                    level[nr][c] = max(currLevel, abs(nr-r));
                    pq.push({level[nr][c], {nr, c}});
                }
            }
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rocks(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> rocks[i][j];
        }
    }
    cout << findLevel(rocks) << endl;
    return 0;
}
