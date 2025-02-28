#include <iostream>
#include <stack>
using namespace std;

bool getBalance(const string& str){
    stack<char> s;

    for (char c : str){
        if(c == '(' || c == '[')   
            s.push(c); 
        else if(!s.empty() && ((c == ')' && s.top() =='(') || (c == ']' && s.top()=='[')))
            s.pop();
        else if(c == ')' || c == ']')
            return false;
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main(){
    string str;

    while(true){
        getline(cin, str);
        
        if(str == ".")    {
            break;
        }
        
        string answer = getBalance(str)? "yes": "no";
        cout << answer << endl;

    }

    return 0;
}