#include <iostream>
#include <vector>
using namespace std;

int getGCD(int a, int b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(){
    int n, s, gcd;
    cin >> n >> s;

    vector<int> distance(n);
    for (int i =0; i<n; i++){
        cin >> distance[i];
        distance[i] -= s;
    }

    gcd = distance[0];
    for (int i=0; i<n; i++){
        gcd = getGCD(max(gcd, distance[i]), min(gcd, distance[i]));
    }

    cout << ((gcd>0) ? gcd: (gcd*(-1)));

    return 0;
}