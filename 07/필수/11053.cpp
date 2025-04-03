#include <iostream>
#include <vector>
using namespace std;

// i 포함 시 lis와 전체 lis 분리
int main(){
    int n;
    cin >> n;
    vector<int> v(n), dp(n);

    for(int i =0; i< n; i++){
        cin >> v[i];
    }

    dp[0] = 1;
    for(int i=1; i<n; i++){
        // i마다 len 갱신(안하면 dp는 i가 포함된 것 중 가장 긴 증가수열)
        int len = 0;
        for(int k = 0; k<i ; k++){
            if(v[i] > v[k]){
                len = max(len,dp[k]);
            }
        }
        dp[i] = len + 1;
    }

    // 전체 최장길이
    int max_len = 0;
    for(int i=0; i<n;i++){
        if(max_len < dp[i]){
            max_len = dp[i];
        }
    }

    cout << max_len;
    return 0;
}