#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void getInput(int n, priority_queue<int, vector<int>, greater<int>>& pq){

    for (int i=0; i<n*n; i++){  // input n^2개
        int input;
        cin >> input;

        if(pq.size() < n){
            pq.push(input);
        }
        else if (pq.top() < input){
                pq.pop();
                pq.push(input);
            }   // 현재 큐에서 가장 작은 수
    }

}

int main(){
    ios::sync_with_stdio(false);  // **입출력 최적화**
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    getInput(n, pq);

    cout <<  pq.top();
    return 0;
}