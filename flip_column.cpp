#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int allOneRows(int n,int m, int k, vector<vector<int>> &mat){
    map<vector<int>,int> rowCount;
    
    for(int i=0; i<n; i++){
        rowCount[mat[i]]++;
    }
    
    int ans=0;
    
    for(const pair<vector<int>,int> &x:rowCount){
        int zeroCnt= count(x.first.begin(),x.first.end(),0);
        
        if(zeroCnt<=k && zeroCnt%2==k%2){
            ans=max(ans,x.second);
        }
    }
    return ans;
}

int main() {
    int n,m,k;
    
    cin>>n>>m>>k;
    
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> mat[i][j];
        }
    }
    cout<< allOneRows(n,m,k,mat);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}