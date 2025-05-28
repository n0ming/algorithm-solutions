#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

//1000개의 예약이 최대로 가능하기 때문에 
//1부터 1000개까지 방이 존재하다고 가정하고 for문
//시간 순대로 방 줘보기 

int strToInt(string time){
    string si, bun;
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    
    return hour*60+minute;
}

struct Node{
    int finish;
    bool operator>(const Node& other) const{
        return finish > other.finish;
    }
};
int solution(vector<vector<string>> book_time) {
    int result = 0;
    sort(book_time.begin(), book_time.end());
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for(auto book: book_time){
        int startTime = strToInt(book[0]);
        int finishTime = strToInt(book[1])+10;
                
        if(!pq.empty()) {
            Node n = pq.top();
            if(n.finish<=startTime) {
                pq.pop(); //있으면 pop
            }
        }
        pq.push({finishTime});
        
        int pqSize = pq.size();
        result = max(result, pqSize);
    }
    return result;
}
