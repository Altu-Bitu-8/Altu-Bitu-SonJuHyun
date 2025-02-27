#include <iostream>
#include <stack>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    stack<int> a_digits, b_digits, sum;
    int carry = 0;
    
    for (int i = 0; i <= a.size() - 1; i++) a_digits.push(a[i] - '0');
    for (int i = 0; i <= b.size() - 1; i++) b_digits.push(b[i] - '0');

    while(!a_digits.empty() || !b_digits.empty()){
        int digit_a = !a_digits.empty() ? a_digits.top() : 0;
        int digit_b = !b_digits.empty() ? b_digits.top() : 0;
        
        sum.push((digit_a + digit_b+ carry) % 10);
        carry= (digit_a + digit_b + carry) / 10;

        if (!a_digits.empty()) a_digits.pop();
        if (!b_digits.empty()) b_digits.pop();
    }

    if (carry)  cout << carry;
    
    while(!sum.empty()){
        cout << sum.top();
        sum.pop();
    }
    
    return 0;
}