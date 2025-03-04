#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <utility>

using namespace std;

vector<int> currPath;
vector<int> bestPath;
int minCost = INT_MAX;

int findCost(vector<int> nodes) {
    int cost = 0; 
    for(int i = 0; i < nodes.size(); i++) {
        cost += nodes[i];
    }
    return cost;
}

void dfs (vector<vector<int>> &adjList, vector<bool> visited, int curr, vector<int> &currPath) {
    visited[curr] = true;
    currPath.push_back(curr);
    for(int i : adjList[curr]) {
        if(!visited[i]) {
            dfs(adjList, visited, i, currPath);
        }
        else {
            if(currPath[0] != i) {
                continue;
            }
            else {
                int cycleCost = findCost(currPath);
                if(cycleCost < minCost) {
                    minCost = cycleCost;
                    bestPath = currPath;
                }
            }
        }
    }
    visited[curr] = false;
    currPath.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    vector<bool> visited(n+1, false);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        dfs(adjList, visited, i, currPath);
    }
    sort(bestPath.begin(), bestPath.end());
    for(int i = 0; i < bestPath.size(); i++) {
        cout << bestPath[i] << " ";
    }
    cout << endl;
    return 0;
}