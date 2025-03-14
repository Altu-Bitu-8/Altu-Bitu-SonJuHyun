#include <iostream>
#include <vector>
using namespace std;

int main(){
    int e, s, m;
    cin >> e >> s >> m;

    for(int year = 1 ; year <= 15*28*19; year++){
        if (year % 15 == e % 15 && year % 28 == s % 28 && year % 19 == m % 19){
            cout << year;
            break;
        }
    }

    return 0;
}