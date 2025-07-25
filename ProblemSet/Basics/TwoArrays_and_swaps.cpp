#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define int long long

void solver(vector<int> a, vector<int> b, int n, int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());

    int swaps = 0;

    int i = 0;
    
    while(swaps < k && i < n){
        if(a[i] < b[i]){
            a[i] = b[i];
            swaps++;
        }
        i++;
    }
    int sum = 0;
    
    for(int i : a){
        sum += i;
    }
    cout << sum << endl;
    return;
}

int32_t main() {
    fast_io

    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        for(int i = 0; i<n; i++){
            cin >> b[i];
        }

        solver(a,b,n,k);
    }

    return 0;
}
