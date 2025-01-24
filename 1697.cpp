#include <iostream>
#include <queue>

using namespace std;

int N, M, result;
void solve(){
    queue<pair<int,int>> q;
    int visit[100001]={0};
    
    visit[N] = 1;
    q.push({N, 0});
    
    while(!q.empty()){
        int location = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(location == M) { 
            result = min(result, time); //인접한 노드를 하나씩 넓게 확인하니까 가장 빨리 도달하는 노드를 확인 할 수 있음
            return;
        }
    
        int next_location[3] = {location+1, location-1, location*2};
        for(int i=0; i<3; i++){
            if(next_location[i] <=0 || next_location[i] > 100000 || visit[next_location[i]] !=0) continue;
            visit[next_location[i]] = 1;
            q.push({next_location[i], time+1});
        }
    }
    return;
}
int main(){
    cin >> N >> M;
    
    result = abs(N-M);
    solve ();
    
    cout << result;
    return 0;
}
