#include <iostream>
using namespace std;

// 연산수  <= 3 000 000이니까 벡터에 입력 저장 시 메모리 초과
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, x;
    string op;
    int k = 0;  
    cin >> m;

    while (m--) {
        cin >> op;
        if (op == "add") {
            cin >> x;
            k |= (1 << x);
        } else if (op == "remove") {
            cin >> x;
            k &= ~(1 << x);
        } else if (op == "check") {
            cin >> x;
            cout << ((k & (1 << x)) ? 1 : 0) << "\n";
        } else if (op == "toggle") {
            cin >> x;
            k ^= (1 << x);
        } else if (op == "all") {
            k = (1 << 21) - 1;  
        } else if (op == "empty") {
            k = 0;
        }
    }

    return 0;
}
