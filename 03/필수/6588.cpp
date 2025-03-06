#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int n, vector<bool> &is_prime){
    return is_prime[n];
}

int  main(){
    const int MAX = 1000000;

    queue<int> input;
    vector<bool> prime(MAX+1, true);  // 1000001 !!

    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++){
        if (prime[i]){
            for (int j = i * i; j <= MAX ; j+= i){
                prime[j] = false;
            }
        }
    }

    while(true){
        int n;
        cin >> n;
        if(n == 0)  break;
        input.push(n);
    }

    while(!input.empty()){
        int n = input.front();  // n은 짝수
        int a = n-1;    // a는 홀수
        bool found = 0;

        while(a > 1){
            if (isPrime(a, prime) && isPrime(n-a, prime)){
                cout << n << " = " << n-a << " + " << a << "\n";;
                found = 1;
                break;
            }   
            a -= 2;
        }
        
        if (!found){
            cout << "Goldbach's conjecture is wrong.\n";
        }

        input.pop();
    }

    return 0;
}