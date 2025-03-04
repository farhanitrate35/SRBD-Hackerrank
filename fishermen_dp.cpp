#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int gate1Pos, gate2Pos, gate3Pos;

int abs(int a) {
    return a < 0 ? -a : a;
}

int hashValue (int a, int b, int c) {
    return a * 10000 + b * 100 + c;
}

vector<vector<int>> dp(12, vector<int>(1000005, -1));

int minCost(int pos, int fishers1, int fishers2, int fishers3)
{
    if(fishers1 < 0 || fishers2 < 0 || fishers3 < 0) return INT_MAX / 2;
    if(pos > n) {
        return (fishers1 == 0 && fishers2 == 0 && fishers3 == 0) ? 0 : INT_MAX / 2;
    }
    int hashIndex = hashValue(fishers1, fishers2, fishers3);
    if(dp[pos][hashIndex] != -1) return dp[pos][hashIndex];

    int takenFisher1 = 1 + abs(gate1Pos - pos) + minCost(pos + 1, fishers1 - 1, fishers2, fishers3);
    int takenFisher2 = 1 + abs(gate2Pos - pos) + minCost(pos + 1, fishers1, fishers2 - 1, fishers3);
    int takenFisher3 = 1 + abs(gate3Pos - pos) + minCost(pos + 1, fishers1, fishers2, fishers3 - 1);
    int noFisherTaken = minCost(pos + 1, fishers1, fishers2, fishers3);

    return dp[pos][hashIndex] = min(min(takenFisher1, takenFisher2), min(takenFisher3, noFisherTaken));
}
int main()
{
    cin >> n;
    int fishers1, fishers2, fishers3;
    cin >> gate1Pos >> gate2Pos >> gate3Pos;
    cin >> fishers1 >> fishers2 >> fishers3;

    cout << minCost(1, fishers1, fishers2, fishers3) << endl;
    return 0;
}