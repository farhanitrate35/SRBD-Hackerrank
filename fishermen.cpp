#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int minDist(int n, vector<int> gates, vector<int> men) {
    int gate1last = n - men[0] - men[1] - men[2] + 1;
    int gate2last = gate1last + men[0];
    int gate3last = gate2last + men[1];
    
    int ans = INF;
    for(int i = 1; i <= gate1last; i++) {
        for(int j = i+men[0]; j <= gate2last; j++) {
            for(int k = j+men[1]; k <= gate3last; k++) {
                int dist = 0; 
                for(int p = i; p < i+men[0]; p++) {
                    dist+=abs(gates[0] - p) + 1;
                }
                for(int p = j; p < j+men[1]; p++) {
                    dist+=abs(gates[1] - p) + 1;
                }
                for(int p = k; p < k+men[2]; p++) {
                    dist+=abs(gates[2] - p) + 1;
                }
                ans = min(ans, dist);
            }
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> men(3);
    vector<int> gates(3);
    for(int i = 0; i < 3; i++) {
        cin >> gates[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> men[i];
    }
    cout << minDist(n, gates, men) << endl;
    return 0;
}
