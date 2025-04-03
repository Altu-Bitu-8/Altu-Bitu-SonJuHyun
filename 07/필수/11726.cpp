#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    // dp 저장 
    for(int i=1; i <= n; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int k=1; k<i ; k++){
            dp[i][k] = (dp[i-1][k-1] + dp[i-1][k]) % 10007;
        }
    }

    int result = 0;
    for(int i=n; i >= n-i; i--){
        result += dp[i][n-i];
    }

    cout << result%10007;

    return 0;
}