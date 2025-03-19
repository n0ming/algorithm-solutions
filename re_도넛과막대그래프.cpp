//1. 정점의 조건을 잘못 설정함
//2. 방문한 노드를 재방문하지 않겠다는 부분을 제거하고 방문한 노드를 다시 방문했으면 이게 cycle인지 eight지를 판단하는 if문을 걸어서 return하게함
//3. queue를 2번쓰지 말고 하나의 함수에서 3개의 그래프 형태를 구하게 함
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

map<int, vector<int>> m_edges;
int outbound[1000000], inbound[1000000];
bool visited[1000000] = {false};
int cycle, stick, eight;
vector<int> answer(4, 0);

// BFS를 통해 사이클 여부 확인
void iscycle(int start) {
    bool temp_visited[1000000];
    memset(temp_visited, false, sizeof(temp_visited));
    
    queue<pair<int,int>> q;
    q.push({start,0});
    
    int cnt = 0;
    while (!q.empty()) {
        int from = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (temp_visited[from]) {
            if (from == start && cnt == dist) cycle++;
            else eight++;
            return;
        }
        
        for (int i = 0; i < outbound[from]; i++) {
            int next = m_edges[from][i];
            //if (!temp_visited[next]) { 원래 이 코드가 있었는데 이거 있으면 8자 할때 모든 노드를 거치지않음. 어차피 위 if문 에서 중복되면 바로 return 하니까 괜찮음. 
                q.push({next,dist+1}); 
                ++cnt;
        }
        temp_visited[from] = true;
    }
    stick++;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    memset(inbound, 0, sizeof(inbound));
    memset(outbound, 0, sizeof(outbound));
    memset(visited, false, sizeof(visited));
    
    int node = -1;
    
    // 간선 정보를 그래프에 반영
    for (int i = 0; i < edges.size(); i++) {
        m_edges[edges[i][0]].push_back(edges[i][1]);
        outbound[edges[i][0]]++;
        inbound[edges[i][1]]++;
    }
    
    // 그래프의 시작점(node) 찾기
    for (int i = 1; i < 1000000; i++) {
        if (inbound[i] == 0 && outbound[i] >= 2) { //정점 개수를 잘못 지정함. 1개는 막대그래프일수 있음.
            node = i;
            break;
        }
    }
    
    // BFS로 탐색
    queue<int> q;
    for (int i = 0; i < outbound[node]; i++) {
        q.push(m_edges[node][i]);
    }
    
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        
        iscycle(from);
    }
    
    // 결과 배열 설정
    answer[0] = node;  // 생성된 정점
    answer[1] = cycle;  // 도넛 모양 그래프 개수
    answer[2] = stick;  // 막대 모양 그래프 개수
    answer[3] = eight;  // 8자 모양 그래프 개수
    
    return answer;
}
