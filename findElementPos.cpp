#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>

long long func(long long a, long long b, long long c, long long n) {
    long long ans = a*n+b*n*floor(log2(n))+c*n*n*n;
    return ans;
}

long long findPos(long long a, long long b, long long c, long long k) {
    long long ans = 0;
    long long l = 1; 
    long long r = 1e6;
    if(c==0) r = 1e15;
    while(l<=r) {
        long long mid = (l+r)/2;
        long long val = func(a, b, c, mid);
        if(k == val) {
            ans = mid;
            break;
        }
        else if(k > val) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return ans;
}

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << findPos(a, b, c, k);
}