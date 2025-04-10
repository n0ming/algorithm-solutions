#include <string>
#include <vector>
#include <set>
#include<algorithm>
//그냥 손안에 있는 카드로 낼수있으면 내고
// 없으면 버린 카드중에 있는지 보고
//더 이상 없으면 포기 하면됨
using namespace std;

bool matchCard(set<int> &hands,set<int> &draws,int n){
    for(auto e: hands){
        auto it = draws.find(n-e);  // ✔️ set이니 std::find 말고 find()
        if(it!=draws.end()){
            hands.erase(e);
            draws.erase(it);
            return true;  // 조건 만족할 때만 return
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1, sum =cards.size()+1;
    
    set<int> hands, draws;
    for(int i=0; i<cards.size()/3; i++){
        hands.insert(cards[i]);
    }
    
    for(int i=cards.size()/3;i<cards.size();i+=2){
        draws.insert(cards[i]);
        draws.insert(cards[i+1]);
        
        if(matchCard(hands,hands,sum)){
        } 
        else if(coin >=1 && matchCard(hands,draws,sum)) 
        {
            coin-=1;
        } 
        else if(coin >=2 && matchCard(draws,draws,sum)) 
        {
            coin-=2;
        } else 
        {
            break;
        }
        answer++;
    }
    return answer;
}
