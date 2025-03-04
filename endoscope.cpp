#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int n, m;

vector<pair<int,int>> vp{{0,1}, {0,-1}, {-1,0}, {1,0}};

bool valid(int x, int y) {
    return (x>=0 && x < n) && (y>=0 && y < m);
}
bool dane(int i) {
    return (i==1||i==3||i==4||i==5);
}
bool bame(int i) {
    return (i==1||i==3||i==6||i==7);
}
bool upore(int i) {
    return (i==1||i==2||i==4||i==7);
}
bool niche(int i) {
    return (i==1||i==2||i==5||i==6);
}

int endoscope(int startX, int startY, int l, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    if(grid[startX][startY] == 0) return 1;
    if(l == 1) return 2;

    queue<pair<pair<int, int>, int>> q;
    q.push({{startX, startY}, 1});
    // visited[startX][startY] = true;

    int ans = 0;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        
        if(c > l) continue;
        ans++;
        
        for(int d = 0; d < 4; d++) {
            int dx = x+vp[d].first;
            int dy = y+vp[d].second;

            if(valid(dx,dy) && !visited[dx][dy] && grid[x][y]!= 0) {
                if(d==0 && dane(grid[x][y]) && bame(grid[dx][dy])) {
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, c+1});
                }
                else if(d==1 && bame(grid[x][y]) && dane(grid[dx][dy])) {
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, c+1});
                }
                else if(d==2 && upore(grid[x][y]) && niche(grid[dx][dy])) {
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, c+1});
                }
                else if(d==3 && niche(grid[x][y]) && upore(grid[dx][dy])) {
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, c+1});
                }
            }
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int startX, startY, l;
        cin >> n >> m >> startX >> startY >> l;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << endoscope(startX,startY,l,grid,visited)-1 << endl;
    }
    return 0;
}