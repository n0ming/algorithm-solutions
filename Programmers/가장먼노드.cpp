#include <string>
#include <vector>
#include <queue>
#include <iostream>
//17분
using namespace std;

vector<int> nodes[20001];
vector<bool> visited(20001,false);

class Node{
  public:
    int node;
    int price;
    
    Node (): node(1), price(0) {
    }
};

int max_price=-1, answer = 0;

void dfs(){
    Node n;
    
    queue<Node> q;
    q.push(n);
    visited[1]=true;
    while(!q.empty()){
        Node qnode = q.front();
        q.pop();
        
        int n = qnode.node;
        
        if(max_price<qnode.price){
            max_price = qnode.price;
            answer = 1;
        } else if(max_price==qnode.price) {
            answer++;
        }
        
        for(auto child: nodes[n]){
            if(visited[child]) continue;
            
            Node tmp;
            tmp.node = child;
            tmp.price=qnode.price+1;
            
            q.push(tmp);
            visited[child]=true;
        }
        
    }
}
int solution(int n, vector<vector<int>> edge) {
    for(auto node: edge){
        nodes[node[0]].push_back(node[1]);
        nodes[node[1]].push_back(node[0]);
    }
    
    dfs();
    return answer;
}
