#include <vector>
#include <queue>
using namespace std;

int x_size, y_size;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, cost;
    
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
    
    bool operator<(const Node& other) const {
        return this->cost > other.cost; // 우선순위 큐에서 작은 cost가 우선
    }
};

int solution(vector<vector<int>> maps) {
    int answer = -1;
    y_size = maps.size();
    x_size = maps[0].size();
    
    // visited 배열을 전역으로 관리
    vector<vector<int>> visited(y_size, vector<int>(x_size, -1));
    visited[0][0] = 0;  // 시작점 방문 표시
    
    priority_queue<Node> pq;
    pq.push(Node(0, 0, 1));  // 시작점 (0, 0)에서 시작
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        // 목표지점에 도달한 경우
        if (cur.x == x_size - 1 && cur.y == y_size - 1)
            return cur.cost;
        
        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int _x = cur.x + dx[i];
            int _y = cur.y + dy[i];
            
            // 맵을 벗어나거나, 벽이거나, 이미 방문한 곳이라면 계속
            if (_x < 0 || _x >= x_size || _y < 0 || _y >= y_size || maps[_y][_x] == 0 || visited[_y][_x] != -1)
                continue;
            
            // 새로 방문한 곳은 비용을 갱신하고 큐에 추가
            visited[_y][_x] = cur.cost + 1;
            pq.push(Node(_x, _y, cur.cost + 1));
        }
    }
    
    return answer;
}
#include <vector>
#include <queue>
using namespace std;

int x_size, y_size;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, cost;
    
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
    
    bool operator<(const Node& other) const {
        return this->cost > other.cost; // 우선순위 큐에서 작은 cost가 우선
    }
};

int solution(vector<vector<int>> maps) {
    int answer = -1;
    y_size = maps.size();
    x_size = maps[0].size();
    
    // visited 배열을 전역으로 관리
    vector<vector<int>> visited(y_size, vector<int>(x_size, -1));
    visited[0][0] = 0;  // 시작점 방문 표시
    
    priority_queue<Node> pq;
    pq.push(Node(0, 0, 1));  // 시작점 (0, 0)에서 시작
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        // 목표지점에 도달한 경우
        if (cur.x == x_size - 1 && cur.y == y_size - 1)
            return cur.cost;
        
        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int _x = cur.x + dx[i];
            int _y = cur.y + dy[i];
            
            // 맵을 벗어나거나, 벽이거나, 이미 방문한 곳이라면 계속
            if (_x < 0 || _x >= x_size || _y < 0 || _y >= y_size || maps[_y][_x] == 0 || visited[_y][_x] != -1)
                continue;
            
            // 새로 방문한 곳은 비용을 갱신하고 큐에 추가
            visited[_y][_x] = cur.cost + 1;
            pq.push(Node(_x, _y, cur.cost + 1));
        }
    }
    
    return answer;
}
