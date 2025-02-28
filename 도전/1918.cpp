#include <iostream>
#include <stack>
using namespace std;

// 다시풀기: 왜 if는 안되고 while이어야하는지 헷갈림.....

/*
    대략적인 방법: 
    피연산자는 바로 출력, 연산자는 다음 연산자 나올때 우선순위 문제 안되면 스택에 있는거 출력
*/

int main(){
    string str;
    getline(cin, str);
    
    stack<char> op;
    
    for (char c : str){
        if (c == ')')
        {   
            while (op.top() != '(')  {
                cout << op.top();
                op.pop();
            }
            op.pop();
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == '*' || c == '/')
        {
            while(!op.empty() && (op.top() == '*' || op.top() == '/')) 
                {
                    cout << op.top();
                    op.pop();   
                }     
            op.push(c);
        }
        else if (c == '+' || c == '-')
        {
            while(!op.empty() && op.top() != '(') 
                {
                    cout << op.top();
                    op.pop();   
                }
            op.push(c);
        }
        else if (c != '(')    cout << c; // 피연산자일 때
    }
    while(!op.empty()) 
    {
        cout << op.top();
        op.pop();
    }
    return 0;
}