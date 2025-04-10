#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int solution(vector<string> maps) {
    int answer = -1;
    
    queue <pair<pair<int,int>,int>> q;
    
    int Lx = -1, Ly= -1;
    int Lpath = -1;
    int time = 2147000000;
    vector<vector<bool>> visited(maps.size(),(vector <bool> (maps[0].size(),false)));
    
    for(int i=0;i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j]=='S') {
                Lpath = i;
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }
    if(Lpath==-1) return -1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int path = q.front().second;
        q.pop();
        //cout << x << "," << y << " " <<path << endl;

        if(maps[x][y]=='L') {
            Lpath = path;
            Lx = x;
            Ly=y;
            break;
        }
        for(int i=0; i<4; i++){
            int tmp_x = x+dx[i];
            int tmp_y = y+dy[i];
            if(tmp_x<0 || tmp_x>=maps.size() || tmp_y<0 || tmp_y>=maps[0].size()) continue;
            //cout << tmp_x << " " << tmp_y <<endl;
            if(maps[tmp_x][tmp_y]!='X'&&visited[tmp_x][tmp_y]==false) 
            {
                visited[tmp_x][tmp_y] = true;
                q.push({{tmp_x,tmp_y},path+1});
            }
        }   
    }
    
    if(Lx==-1) return -1;
    while(!q.empty()){
        q.pop();
    }
    fill(visited.begin(), visited.end(), vector<bool>(maps[0].size(), false));
    q.push({{Lx,Ly},Lpath});
    visited[Lx][Ly]=true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int path = q.front().second;
        q.pop();
        
        if(maps[x][y]=='E') {
            return path;
        }
        for(int i=0; i<4; i++){
            int tmp_x = x+dx[i];
            int tmp_y = y+dy[i];
            if(tmp_x<0 || tmp_x>=maps.size() || tmp_y<0 || tmp_y>=maps[0].size()) continue;
            //cout << tmp_x << " " << tmp_y <<endl;
            if(maps[tmp_x][tmp_y]!='X'&&visited[tmp_x][tmp_y]==false) {
               visited[tmp_x][tmp_y] = true;
                q.push({{tmp_x,tmp_y},path+1});
            }
        }   
    }
    return -1;
}
