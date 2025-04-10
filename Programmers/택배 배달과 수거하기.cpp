#include <string>
#include <vector>
#include <iostream>

//가장 끝집서부터 n개의 택배를 배달 시작 
//돌아오면서 수거
using namespace std;
vector<int> tmp_deliveries;
vector<int> tmp_pickups;

void give_delivery(int delivery, int house){
    if(delivery ==0 || house < 0) return; //수거할게 없거나 이미 수용치를 넘었음
    
    if(tmp_deliveries[house]>0){
        int amount = min(tmp_deliveries[house],delivery);
        tmp_deliveries[house] -= amount;
        delivery -= amount;
    }
    // if(delivery>=tmp_deliveries[house]) {
    //     delivery -= tmp_deliveries[house];
    //     tmp_deliveries[house] = 0;
    // }
    // else {
    //     tmp_deliveries[house] -= delivery;
    //     delivery =0;
    // }
    give_delivery(delivery, house-1);
}

void take_pickup(int pickup, int house, int cap){
    if(pickup ==cap || house < 0) return;
    
    if (tmp_pickups[house] > 0) {
        int amount = min(cap - pickup, tmp_pickups[house]);
        tmp_pickups[house] -= amount;
        pickup += amount;
    }
    // if(tmp_pickups[house] == 0) {
    //     take_pickup(pickup, house-1, cap);
    //     return;
    // }
    // if(cap-pickup<=tmp_pickups[house]) { //수용량보다 수거량이 많을 경우
    //     tmp_pickups[house] -= cap-pickup;
    //     pickup = cap;
    // }
    // else { //수용량이 더 클경우
    //     pickup = cap-pickup - tmp_pickups[house];
    //     tmp_pickups[house] = 0;
    // }
    take_pickup(pickup, house-1, cap);
}
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    
    long long result = 0;
    //for(int i =0; i<=cap; i++){
        for(auto e: deliveries){ //복사
            tmp_deliveries.push_back(e);
        }
        for(auto e: pickups){ //복사
            tmp_pickups.push_back(e);
        }
        for(int j=n; j>0; j--){
            //cout << tmp_deliveries[j] << endl;
            if(tmp_deliveries[j-1]>0 || tmp_pickups[j-1]>0){
                // cout << j << endl;
                give_delivery(cap, j-1);
                take_pickup(0,j-1,cap);
                result += j*2;
                
                if(tmp_deliveries[j-1]>0 || tmp_pickups[j-1]>0) j += 1;// 여러번 갈수있는것을 생각못함
            } 
        }
        
    //}
    return result;
}
