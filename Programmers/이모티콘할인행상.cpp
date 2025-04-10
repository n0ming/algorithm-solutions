//조건을 잘 보자
#include <string>
#include <vector>
#include <iostream>

//할인 최소 값으로 했을때 기준가격보다 크면 이 사용자는 가입 안됨 -> 이것보다는 할인률을 이하로
//100명에 대해서 각각 100번 경우의 수 구하기 -> 100*100
using namespace std;

int ans_people = 0;
int ans_total = 0;
vector<vector<int>> global_users;
vector<int> global_emoticons;
vector<int> discount_rates = {10, 20, 30, 40};

void dd(vector<int> &sales, int i){
    if(i == global_emoticons.size()) {
        int p =0, total = 0;
        
        for(int j=0; j<global_users.size(); j++){
            int total_emoticon = 0;
            
            for(int k=0; k<global_emoticons.size(); k++){
                if(sales[k]>=global_users[j][0]) { //할인
                    total_emoticon += global_emoticons[k] - global_emoticons[k]*sales[k]/100; 
                }
            }
            
            if(total_emoticon>= global_users[j][1]) p++;
            else total += total_emoticon;
        }
        if(ans_people<p) {
            ans_people = p;
            ans_total = total;
        } else if(ans_people == p) ans_total = max(ans_total, total);
        return;
    }
    
    for (int sale : discount_rates) {
        sales[i] = sale;
        dd(sales, i + 1);
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    
    global_users = users;
    global_emoticons = emoticons;
    
    //최소 할인율 기준
    // int min_sale = 100;
    // for(int i=0; i<users.size(); i++){
    //     int total = 0;
    //     for(auto e : emoticons){
    //         total += e*(100-users[i][0])/100;
    //     }
    //     if(total<= users[i][1]) min_sale = min(min_sale,users[i][0]);
    // }
   
    //전체 경우의 수 구하기
    vector<int> sales(emoticons.size(),0);
    dd(sales,0);
    
    //cout << ans_total << endl;
    //cout << ans_people;
    answer[0]=ans_people;
    answer[1]=ans_total;
    
    return answer;
}
