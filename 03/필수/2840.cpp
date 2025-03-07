#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <set>

using namespace std;

vector<char> getWheel(vector<char>& wheel, stack<string>& input, int n){
   int s = 0 , i = 0;
   set<char> used;  // 바퀴에 알파벳 중복 불가!!

   while(!input.empty()){
    int next_s;
    char c;
    string str = input.top();
    input.pop();

    stringstream ss(str);
    ss >> next_s >> c;  // 바로 int로 받을 수 있음

    if(wheel[(i+s)%n] == '?'){
        if (used.count(c)){
            return {'!'};
        }
        wheel[(i+s)%n] = c;
        used.insert(c);
        i = (i+s)%n;
    }
    else if(wheel[(i+s)%n] == c){
        i = (i+s)%n;
    }
    else{
        wheel = {'!'};
        break;
    }
    s = next_s;
   } 
    
    return wheel;
}

int main(){
    int n,k;
    cin >> n >> k;
    cin.ignore();

    vector<char> wheel(n,'?');
    stack<string> input;

    for(int i = 0; i<k; i++){   // Input 저장
        string str;
        getline(cin, str);
        input.push(str);
    }   

    vector<char> result = getWheel(wheel, input, n);

    for(char c:result){
        cout << c;
    }

    return 0;
}