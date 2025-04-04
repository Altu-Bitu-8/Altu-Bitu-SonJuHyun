#include <iostream>
#include <vector>
using namespace std;

int check_h(int k, vector<char>& table){
    int count = 0;
    for(int i = 0; i<table.size(); i++){
        if(table[i]!='P'){
            continue;
        }
        // i >=1, table[i]가 사람일 때는 앞뒤 모두 체크: 제일 작은거부터 먹어야함 가까운 순으로 먹으면 먼 애들이 나중에 필요할때 못먹음
        for(int j = i-k; j<=i+k; j++){
            if(j<0 || j>=table.size()){
                continue;
            }
            if(table[j]=='H'){
                table[j] = 'E';
                count ++;
                break;
            }
        }
    }
    return count;
}

int main(){
    int n, k;
    cin >> n >> k;

    // cin>.get()은 줄바꿈까지 읽어서 틀림!
    string table;
    cin >> table;

    vector<char> table_vector(table.begin(), table.end()); // string을 vector로 변환

    cout << check_h(k, table_vector);

    return 0;
}