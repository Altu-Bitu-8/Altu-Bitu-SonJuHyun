#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 덱 쓸때는 쓸 방향 적어놓고 하기...
void to_ground(deque<int>& deck, deque<int>& ground){   // 덱에서 가장 위치한 숫자 그라운드에 내려놓음
    if(!deck.empty()){
        ground.push_back(deck.back());
        deck.pop_back();
    }
}

bool do_hit_bell(deque<int> groundDo, deque<int> groundSu){
    // 그라운드 가장 위 카드가 5면 도도가 
    if((!groundDo.empty() && groundDo.back() == 5) || (!groundSu.empty() && groundSu.back() == 5)){
        return true;
    }
    return false;
}

bool su_hit_bell(deque<int> groundDo, deque<int> groundSu){
    // 숫자 합이 5, 그라운드 둘다 카드 존재하면 수연이가
    if(!groundDo.empty() && !groundSu.empty() && (groundDo.back() + groundSu.back()) == 5){
        return true;
    }
    return false;
}

void to_deck(deque<int>& ground, deque<int>& deck){
    while(!ground.empty()){
        deck.push_front(ground.front());    // 뒤집어서 가져오기!
        ground.pop_front(); 
    }
}

int  main(){
    int n, m;
    cin >> n >> m;

    deque<int> deckDo;
    deque<int> deckSu;

    deque<int> groundDo;
    deque<int> groundSu;

    for(int i=0; i< n; i++){
        int a, b;
        cin >> a >> b;
        deckDo.push_back(a);    // 아래가 먼저(front)
        deckSu.push_back(b);
    }

    bool turn = true; // 게임 한번에 한명만 내는거임..
    // M번 동안 게임(2-4)
    int cnt = 0;
        while(true){
            cnt ++;
            if(turn){
                to_ground(deckDo, groundDo);
                if(deckDo.empty()){
                    break;
                }
            }
            else{
                to_ground(deckSu, groundSu);
                if(deckSu.empty()){
                    break;
                }
            }

            if(su_hit_bell(groundDo, groundSu)){
                to_deck(groundDo, deckSu);
                to_deck(groundSu, deckSu);
            }
            if(do_hit_bell(groundDo, groundSu)){
                to_deck(groundSu, deckDo);
                to_deck(groundDo, deckDo);
            }        
            turn = !turn;

            if(cnt == m){
                break;
            }
        }

    if(deckDo.size() > deckSu.size()){
        cout << "do";
    }
    else if (deckDo.size() < deckSu.size()){
        cout << "su";
    }
    else{
        cout << "dosu";
    }

    return 0;
}