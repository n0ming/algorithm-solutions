#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool isPrime(int x){
    if (x<2) return false;
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0) return false;
    }
    return true;
}
void solve(string origin, string target){
    queue <pair<string, int>> q;
    bool visit[10000] = {false};
    q.push({origin, 0});
    visit[stoi(origin)] =true;
    
    while(!q.empty()){
        string num = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(num==target) {
            cout << time << endl;
            return;
        }
        
        for(int i=0; i<4; i++){
            for(int j=0; j<10; j++){
                string temp = num;
                temp[i] = j +'0';
                int next_num = stoi(temp);
                
                if(next_num <1000 || !isPrime(next_num)|| visit[next_num]) continue;
                visit[next_num] = true;
                q.push({temp, time+1});
            }
        }
    }
    cout << "Impossible"<< endl;
}
int main(){
    int N;
    cin >> N;
    
    string arr[N][2];
    for (int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1]; 
    }
    
    for(int i=0; i<N; i++) {
        solve(arr[i][0], arr[i][1]);
    }
    
    return 0;
}
