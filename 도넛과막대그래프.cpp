#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
map <int, vector<int>> m_edges;
int outbound[1000000], inbound[1000000];
bool visited[1000000] = {false};
int cycle, stick, eight;

bool iscycle(int check){
    bool temp_visited[1000000];
    memset(temp_visited, false, sizeof(temp_visited));
    
    queue <int> q;
    q.push(check);
    while(!q.empty()){
        int from = q.front();
        q.pop();
        
        if(temp_visited[from]) {
            if(from == check) {
                for(int i=0; i<1000000;i++){
                    if(temp_visited[i]) visited[i] = true;
                }
                return true;
            } else {
                return false;
            }
        } 
        
        for(int i=0; i<outbound[from]; i++){
            int next = m_edges[from][i];
            if(!temp_visited[next]) q.push(next);   
        }   
        temp_visited[from] = true;
    }
    return false;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    memset(inbound, 0,sizeof(inbound));
    memset(outbound, 0,sizeof(outbound));
    memset(visited, 0,sizeof(visited));
    int node=-1;
    
    for(int i=0; i<edges.size(); i++ ){
        m_edges[edges[i][0]].push_back(edges[i][1]);
        outbound[edges[i][0]]++;
        inbound[edges[i][1]]++;
    }
    for(int i=1; i<1000000; i++){
        if(inbound[i]==0) {
            node = i;
            break;
        }
    }
    //kingnode(node);
    int check = node;
    queue <int> q;
    for(int i=0; i<outbound[check]; i++){
        q.push(m_edges[check][i]);   
    }
    while(!q.empty()){
        int from = q.front();
        q.pop();
        
        int to_num = outbound[from];
 
        if(iscycle(from)) {cycle++; continue;}
        if(to_num ==0) {
            stick++;
        } 
        //    else if(visited[from]) {
        //     eight++;
        // } else {
        //     for(int i=0; i<to_num; i++){
        //         int next = m_edges[from][i];
        //         q.push(next);   
        //     }
        // }
        visited[from]==true;
    }
    
    answer[0]= node;
    answer[1] = cycle;
    answer[2] = stick;
    answer[3] = outbound[check] - stick - cycle;
    
    return answer;
}
