#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> v;
    for(int i=0; i<n; i++){
        long long k;
        cin >> k;
        v.push(k);  // 300 400 500 400 300
    }

    long long prior = 0;  
    long long current = 0;
    while(!v.empty()){
        prior = current;    // 직전 행성 거리
        current = v.top();  // c: 300 v: 400 
        
        v.pop();

        if(prior == 0){ // 첫번째 행성은 굳이 X
            continue;
        }
        if (current < prior) {
            // current * 배수 >= prior 가 되도록 배수 계산
            current = ((prior + current - 1) / current) * current;
        }
    }
    cout << current;

    return 0;
}