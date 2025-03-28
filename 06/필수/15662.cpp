#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 톱니바퀴 회전 함수
void rotate_wheel(int i, int d, vector<deque<int>>& wheel) {
    if (d == 1) {  // 시계방향
        wheel[i].push_front(wheel[i].back());
        wheel[i].pop_back();
    } else if (d == -1) {  // 반시계방향
        wheel[i].push_back(wheel[i].front());
        wheel[i].pop_front();
    }
}

void rotate_wheels(int index, int d, vector<deque<int>>& wheel) {
    vector<int> dir(wheel.size(), 0);  
    dir[index] = d;

    // 왼쪽 톱니바퀴 
    for (int i = index; i > 0; --i) {
        if (wheel[i][6] != wheel[i - 1][2]) {
            dir[i - 1] = -dir[i];  
        } else {
            break;
        }
    }
    
    // 오른쪽 톱니바퀴 
    for (int i = index; i < wheel.size() - 1; ++i) {
        if (wheel[i][2] != wheel[i + 1][6]) {
            dir[i + 1] = -dir[i];  
        } else {
            break;
        }
    }
    
    for (int i = 0; i < wheel.size(); ++i) {
        if (dir[i] != 0) {
            rotate_wheel(i, dir[i], wheel);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, K;
    cin >> T;  
    vector<deque<int>> wheel(T);

    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            wheel[i].push_back(c - '0');
        }
    }
    
    cin >> K;  
    for (int i = 0; i < K; ++i) {
        int n, d;
        cin >> n >> d;
        rotate_wheels(n - 1, d, wheel);  
    }
    
    int count = 0;
    for (int i = 0; i < T; ++i) {
        if (wheel[i][0] == 1) {
            count++;
        }
    }
    cout << count << '\n';
    
    return 0;
}