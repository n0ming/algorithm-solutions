//첫번째 40분때에는 완성을 못함
//두번째 50분때에는 완성을 함 -> 시간 초과
//세번째 60분때에는 성공 -> q 접근에 대한 중복 제거하기
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string>

//지게차는 외부와 연결된 부분만 접근 가능 -> 한번 요청
//크레인은 안쪽까지도 가능 -> 두번 요청
//배열로 했을때 상하좌우에 빈공간(-1)이 있는가? -> 이거를 반복해서 가장 바깥쪽까지 도달하는가? -> 그러면 외부와 연결되어있는것이기에 지게차로도 가능
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool IsOpen(vector<string> storage, int row, int col){
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(storage.size(),vector<bool>(storage[0].size(),false));
    q.push({row,col});
    while(!q.empty()){
        int q_row = q.front().first;
        int q_col = q.front().second;
        q.pop();
        
        if(visited[q_row][q_col]) continue;
        visited[q_row][q_col]=true;
        
        if(q_row<=0 || q_row>=storage.size()-1 || q_col<=0 || q_col>=storage[0].size()-1) return true;
        
        for(int i=0; i<4; i++){
            int next_row = q_row+dx[i];
            int next_col = q_col+dy[i];
            if(storage[next_row][next_col] =='0') q.push({next_row, next_col});
        }
    }
    return false;
}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    answer = storage.size()*storage[0].size();
    
    for(string r: requests){
        queue<pair<int,int>> q;
        if(r.size()==2){
            for(int i=0; i<storage.size(); i++){
                for(int j=0; j<storage[i].size(); j++){
                    if(storage[i][j]==r[0]) {
                        storage[i][j]='0';
                        answer -=1;
                    }
                }
            }
        }else{
             for(int i=0; i<storage.size(); i++){
                for(int j=0; j<storage[i].size(); j++){
                    if(storage[i][j]==r[0]) {
                        if(IsOpen(storage, i, j)){
                            q.push({i,j});
                            answer -=1;
                        }
                    }
                }
            }
        }
        while(!q.empty()){
            int tmp_i = q.front().first;
            int tmp_j = q.front().second;
            q.pop();
            storage[tmp_i][tmp_j]='0';
        }
    }
    return answer;
}
