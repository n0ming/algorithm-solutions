//전체 다 하면 안됨... 시간 오바
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
    vector<vector<int>> check_oil(500,vector<int> (500, 0));
    vector<vector<bool>> visited(500,vector<bool> (500, false));
    vector<vector<int>> check_oil_group(500,vector<int> (500, 0));
    //int result =0;
    int n = 1;
    
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<land[0].size(); j++){
            if(land[i][j]==1 && check_oil_group[i][j]==0) {
                queue<pair<int,int>> q;
                q.push({i,j});
                
                int result = 0;
                vector<pair<int, int>> positions;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if(x<0 || x>=land.size() || y<0 || y>=land[x].size() || land[x][y]!=1 || visited[x][y]) continue; 

                        result++; //석유 발견
                        check_oil_group[x][y] =n;
                        positions.push_back({x, y});
                    
                    visited[x][y] = true;

                    for(int i=0; i<4; i++){
                        q.push({x+dx[i],y+dy[i]}); //좌우상하 이동
                    }
                }
                for (auto [x, y] : positions) {
                    check_oil[x][y] = result;
                }
                n += 1;
            }
        }
    }

    for(int tube=0; tube<land[tube].size(); tube++){
        int result =0;
        vector<bool> counted_group(n, false);
        
        for(int col=0; col<land.size(); col++){
            int group_num = check_oil_group[col][tube];
            if(land[col][tube]==1 && !counted_group[group_num]) { // 여기 중복 첵크가 제대로 안되어 있어서 답이 틀렸던거임.. 그냥 복잡하게 하지 말고 bool 변수 하나더 넣자...
                result+= check_oil[col][tube];
                counted_group[group_num] = true;
            }
        }
        
        answer = max(answer,result);
    }
    return answer;
}
