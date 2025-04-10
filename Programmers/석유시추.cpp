#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

//500개의 경우의수 다하자
//뚫었을때 1인 곳이 있으면 좌우양옆에 1이 있는 것을 count 시작. -> visited로 2차원 벡터 하나더 만들기
//맨 아래 까지 도달하기
//10초면 최대 10^9승까지 가능하기에 500^3승까지도 가능

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

// void dfs(){
    
// }
int solution(vector<vector<int>> land) {
    int answer = 0;
    //미리 석유의 양을 첵크하자
//     for(int i=0; i<land.size(); i++){
//         for(int j=0; j<land.size(); j++){
            
//         }
//     }
    cout << land.size();
    for(int tube=0; tube<land[tube].size(); tube++){
        vector<vector<bool>> visited(500,vector<bool> (500, false));
        int result =0;
        
        for(int col=0; col<land.size(); col++){
            if(land[col][tube]==1) {
                //dfs 함수 호출
                queue<pair<int,int>> q;
                q.push({col,tube});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    if(x<0 || x>=land.size() || y<0 || y>=land[x].size() || land[x][y]!=1 || visited[x][y]) continue; //land 밖으로 나감 혹은 석유 발견 못함
                    
                    if(land[x][y]==1) result++; //석유 발견
                    visited[x][y] = true;
                    
                    for(int i=0; i<4; i++){
                        q.push({x+dx[i],y+dy[i]}); //좌우상하 이동
                    }
                }
            }
        }
        answer = max(answer,result);
    }
    return answer;
}
