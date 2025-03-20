#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

/* k가 움직이고 문제가 없으면 s은 움직일 이유가 아예 없음! (조건의 우선순위가 다름)*/

// 체스판 안에 있는지
bool isValidMove(char x, char y) {
    return (x >= 'A' && x <= 'H' && y >= '1' && y <= '8');
}

// (킹, 스톤) 위치 반환 함수 
pair<string, string> getLocation(string& k, string& s, int dir){
    // 킹의 기존 위치 k, 스톤의 기존 위치 s
    char king_x = k[0], king_y = k[1], stone_x = s[0], stone_y = s[1];
    int dx = 0, dy = 0;

    // 다음 위치
    switch(dir){
        case 1: // 왼쪽으로 이동
            dx--;
            break;
        case 2: // 오른쪽으로 이동
            dx++;
            break;
        case 4: // 아래로 이동
            dy--;
            break;
        case 5: // 왼쪽아래로 이동
            dx--;
            dy--;
            break;
        case 6: // 오른쪽아래로 이동
            dx++;
            dy--;
            break;
        case 8: // 위로 이동
            dy++;
            break;
        case 9: // 왼쪽위로 이동
            dx--;
            dy++;
            break;
        case 10:    //오른쪽 위로 이동
            dx++;
            dy++;
            break;
    }

    char new_k_x = k[0] + dx;
    char new_k_y = k[1] + dy;
    if(isValidMove(new_k_x, new_k_y)){
        k[0] += dx;
        k[1] += dy;
    }

    if(new_k_x == s[0] && new_k_y == s[1]){
        char new_s_x = s[0] + dx;
        char new_s_y = s[1] + dy;

        if (isValidMove(new_s_x, new_s_y)){
            s[0] += dx;
            s[1] += dy;
        }
        else{
            k[0] -= dx;
            k[1] -= dy;
        }
    }
    return make_pair(k,s);
}

int main(){
    string k, s;
    int n;
    cin >> k >> s >> n;

    vector<int> dir(n);

    for (int i = 0; i<n; i++){  // 킹의 움직임
        string dir_string;
        cin >> dir_string;
        
        if(dir_string.find('L') != string::npos){
            dir[i] += 1<<0;
        }
        if(dir_string.find('R') != string::npos){
            dir[i] += 1<<1;
        }
        if(dir_string.find('B') != string::npos){
            dir[i] += 1<<2;
        }
        if(dir_string.find('T') != string::npos){
            dir[i] += 1<<3;
        }
    }

    for (int i : dir){
        pair<string, string> loc = getLocation(k, s, i);
        k = loc.first, s = loc.second;
    }    

    cout << k << "\n" << s;

    return 0;
}