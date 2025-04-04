#include <string>
#include <vector>
#include <queue>

//bfs로 큐를 통해서 하나씩 구조를 내려감
// 루트노드는 낮은 순서부터 시작 -> 단 방문 확인해야함

using namespace std;

vector<int> node_child[1000001];
bool visited[1000001];

int checknode(int node, int size, int check){
    if(node%2==size%2) {
        if(check==2) return -1;
        return 1;
    }
    
    if(node%2!=size%2) {
        if(check==1) return -1;
        return 2;
    }
}

int bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root] =true;
    
    int check = checknode(root, node_child[root].size(), 0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto child: node_child[node]){
            if(!visited[child]) {
                q.push(child);
                visited[child] =true;
                
                check = checknode(child, node_child[child].size()-1, check);
                if(check==-1) return -1;
            }
        }
    }
    
    return check;
}
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    
    for(auto edge: edges){
        node_child[edge[0]].push_back(edge[1]);
        node_child[edge[1]].push_back(edge[0]);
    }
    
    for(auto root: nodes){
        int idx = bfs(root);
        if(idx!=-1) answer[idx-1]++;
        fill(visited, visited + 1000001, false);
    }
        
    return answer;
}
