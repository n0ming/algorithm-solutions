//한번에 통과함
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int valid_server = 0, n = 1;
    int check_time = 0;
    queue<pair<int,int>> add_server_time;
    for(int i=0; i<24; i++){
        pair<int, int> p = add_server_time.front();
        if(i==p.first+k) {
            //cout << i <<"시간: " << valid_server << "감소 " << valid_server-p.second << endl;
            valid_server-=p.second;
            add_server_time.pop();
        }
        
        if(players[i] >= m && players[i] > valid_server*m) {
            answer += players[i]/m - valid_server;
            add_server_time.push({i, players[i]/m - valid_server});
            valid_server = players[i]/m;
        }
        //cout << i <<"시간: " << valid_server << " 수 " <<  players[i] << " valid " << valid_server <<" p " << p.first << " 감소 " << p.second << endl;
    }
    return answer;
}
