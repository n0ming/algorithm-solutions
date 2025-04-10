//시간오바...
//struct을 해야한다는 사실을 너무 뒤늦게 알아차림 -> vector로 고생했음
//나중에 할때는 strcut 안에 다음 next 경로값도 연결해서 넣기
//만약 그렇게 해서 queue를 통해 최적의 경로를 구했을때 break하기 전에 그 struct의 리스트값을 가져오면됨.
//그렇게 경로 다 구하고 나면 0초서부터 n초씩 시뮬레이션 돌려서 충돌나는 값 구하기
#include <string>
#include <queue>
#include <vector>
#include <iostream>

//각 포인트마다 최단 경로 찾기 FOR 문 돌려서 BFS로
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

struct point {
    int x;
    int y;
    int time;
};

struct points {
    int x;
    int y;
    int score;
    int goal;
    int time;
    vector<point> ps;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    queue<struct points> q;
    
    for(int i=0;i<routes.size(); i++){
        int start = routes[i][0];
        
        struct points p;
        p.x= points[start][0];
        p.y = points[start][1];
        p.score = 0;
        p.goal = routes[i][1];
        p.time = 0;
        
        p.ps.resize(routes.size());
        
        for(int j=0;j<routes.size(); j++){
            p.ps[j].x = points[routes[j][0]][0];
            p.ps[j].y = points[routes[j][0]][1];
            p.ps[j].time = 0;
        }
        
        q.push(p);
    }

     while(!q.empty()){
        struct points p = q.front();

        q.pop();

        if(p.goal == -1) continue; //이미 도착함
         
        if(p.x<=0|| p.x>100|| p.y<=0|| p.y>100) continue; //좌표 밖으로 벗어남
         
        for(int i=0;i<p.ps.size(); i++){
            if(p.time == p.ps[i].time && p.x==p.ps[i].x && p.y==p.ps[i].y) p.score++; //기존의 포인트들과 충돌이 났는가?
        }

        if(p.x==points[p.goal][0] && p.y == points[p.goal][1]) {
            p.goal = -1; //도착했으면 도착 처리함
            answer = p.score;
        }
         
        p.time += 1;
        for(int i=0; i<4; i++){
            q.push(p);
        }
        
    }

    return answer;
}
