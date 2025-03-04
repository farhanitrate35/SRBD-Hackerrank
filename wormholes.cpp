#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int manhattan(pair<int, int> x, pair<int, int> y) {
    return abs(x.first-y.first)+abs(x.second-y.second);
}
int dijkstra(vector<vector<int>> &adjMat, int src, int dest) {
    int n = adjMat.size();
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        if(currDist>distance[currNode]) continue;
        for(int nxtNode = 0; nxtNode < adjMat[currNode].size(); nxtNode++) {
            int weight = adjMat[currNode][nxtNode];
            if(distance[nxtNode]>weight+distance[currNode]) {
                distance[nxtNode] = weight+distance[currNode];
                pq.push({distance[nxtNode], nxtNode});
            }
        }
    }
    return distance[dest];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        int v = 2*n+2;
        vector<pair<int, int>> location(v);
        vector<vector<int>> adjMat(v, vector<int>(v, INT_MAX));
        cin >> location[0].first >> location[0].second >> location[v-1].first >> location[v-1].second;
        for(int i = 1; i <=n; i++) {
            cin >> location[i].first >> location[i].second >> location[v-1-i].first >> location[v-1-i].second 
                >> adjMat[i][v-1-i];
            adjMat[v-1-i][i] = adjMat[i][v-1-i];
        }
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                adjMat[i][j] = min(adjMat[i][j], manhattan(location[i], location[j]));
            }
        }
        cout << dijkstra(adjMat, 0, v-1) << endl;
    }
    return 0;
}
