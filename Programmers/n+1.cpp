#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

//2장씩 뽑았을때 왼쪾?오른쪾?안뽑음?뽑음? 경우의 수로 들어감
//손안에 2장 낼게 있음? -> 없으면 끝
//있으면 내기 -> 여러개면 큐 여러개 넣기
//자기가 보유한 카드가 n+1+(전체장수-2)보다 작으면 포기

using namespace std;

struct Card{
    vector<int> cards;
    vector<int> card;
    int coin;
    int round =0;
};

vector<vector<int>> sum_n;
void combination(vector<int> cards, vector<int>& result, int start, int n){
    if(result.size()==2){
        if(result[0]+result[1]==n) sum_n.push_back(result);
        return;
    }
    
    for(int i=start; i<cards.size(); i++){
        result.push_back(cards[i]);
        combination(cards,result, i+1, n);
        result.pop_back();
    }
}

void four_method(queue<Card> &q, vector<int> cards, Card c, int n){
    int draw_start = cards.size() / 3;
    int draw_idx = draw_start + c.round * 2;

    // 카드가 모자라면 못 뽑음
    if(draw_idx >= cards.size()) {
        c.round++;
        q.push(c);
        return;
    }

    if(n == 1 && c.coin >= 1) {
        int pick = cards[draw_idx];
        auto it = find(c.cards.begin(), c.cards.end(), pick);
        if(it != c.cards.end()) c.cards.erase(it);
        c.card.push_back(pick);
        c.coin--;
        c.round++;
        q.push(c);
    }
    else if(n == 2 && c.coin >= 1 && draw_idx + 1 < cards.size()) {
        int pick = cards[draw_idx + 1];
        auto it = find(c.cards.begin(), c.cards.end(), pick);
        if(it != c.cards.end()) c.cards.erase(it);
        c.card.push_back(pick);
        c.coin--;
        c.round++;
        q.push(c);
    }
    else if(n == 3 && c.coin >= 2 && draw_idx + 1 < cards.size()) {
        int pick1 = cards[draw_idx];
        int pick2 = cards[draw_idx + 1];
        auto it1 = find(c.cards.begin(), c.cards.end(), pick1);
        if(it1 != c.cards.end()) c.cards.erase(it1);
        auto it2 = find(c.cards.begin(), c.cards.end(), pick2);
        if(it2 != c.cards.end()) c.cards.erase(it2);
        c.card.push_back(pick1);
        c.card.push_back(pick2);
        c.coin -= 2;
        c.round++;
        q.push(c);
    }
    else if(n == 4 && draw_idx + 1 < cards.size()) { // 아무것도 안 뽑고 넘김
        c.round++;
        q.push(c);
    }
}


Card cardErase(Card my_c, vector<int> s){
    for(int i=0; i<2; i++){
        auto it = find(my_c.card.begin(), my_c.card.end(), s[i]);
        my_c.card.erase(it);
    }
    return my_c;
}
int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    vector<int> result;
    Card c;
    
    for(int i=0; i<cards.size()/3; i++){
        c.card.push_back(cards[i]);
    }
    c.coin = coin;
    c.cards=cards;
    
    queue<Card> q;
    for(int i=1; i<5; i++){
        four_method(q, cards, c, i);
    }
    
    while(!q.empty()){
        Card my_c = q.front();
        q.pop();
        
        combination(my_c.card,result,0,cards.size()+1);
        
        if(sum_n.size()==0) {
            answer = max(answer,my_c.round);
            continue;
        }
        
        for(auto s: sum_n){
            Card tmp = cardErase(my_c, s);
            for(int i=1; i<5; i++){
                four_method(q, cards, tmp, i);
            }
        }
        sum_n.clear();
        
    }
    
    return answer;
}
