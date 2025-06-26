#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    

    vector<vector<int>> road(n+1);
    for(auto r: roads){
        road[r[0]].push_back(r[1]);
        road[r[1]].push_back(r[0]);
    }

    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    
    while(!q.empty()){
        int pos = q.front(); q.pop();
        for(auto next: road[pos]){
            if(dist[next]!=-1) continue;
            dist[next]= dist[pos]+1;
            q.push(next);
        }
    }
    for (int s : sources) {
        answer.push_back(dist[s]);
    }

    return answer;
}
