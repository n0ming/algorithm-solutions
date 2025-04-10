#include <iostream>
#include <queue>

using namespace std;

char cmd[4] ={'D', 'S', 'L', 'R'};

int turn(int num, string cmd){
    int d1 = num / 1000;
    int d2 = (num % 1000) / 100;
    int d3 = (num % 100) / 10;
    int d4 = num % 10;
    
    if(cmd == "L") return d2*1000+d3*100+d4*10+d1;
    return d4*1000+d1*100+d2*10+d3;
}

void solve(int origin, int target){
    queue <pair<int,string>> q;
    bool visit[10000] = {false};
    
    q.push({origin, ""});
    visit[origin] = true;
    
    while(!q.empty()){
        int temp_num = q.front().first;
        string command = q.front().second;
        q.pop();
        
        if(temp_num == target) {
            cout << command << endl;
            return;
        }
        
        for(int i=0; i<4; i++){
            int temp = 0;
            string temp_cmd = command;
            if(i == 0) {
                if(temp_num*2>=10000) temp = (temp_num*2)%10000;
                else temp = temp_num*2;
            }
            else if(i==1) {
                if(temp_num == 0) temp = 9999;
                else temp = temp_num-1;
            } 
            else if(i==2) temp = turn(temp_num,"L");
            else temp = turn(temp_num,"R");
            
            if(!visit[temp]){
                temp_cmd += cmd[i]; 
                q.push({temp, temp_cmd});
                visit[temp] = true;
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    vector<pair<int, int>> test_cases(T);
    for (int i = 0; i < T; i++) {
        cin >> test_cases[i].first >> test_cases[i].second;
    }

    for (int i = 0; i < T; i++) {
        solve(test_cases[i].first, test_cases[i].second);
    }
    return 0;
}
