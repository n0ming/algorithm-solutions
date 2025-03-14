#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int people[60001];
map<pair<int, int>, int> node;  // 간선의 가중치
map<pair<int, int>, int> node_result;  // 최단 거리 저장
vector<int> tree[60001];  // 트리 구조

// BFS로 한 노드에서 다른 모든 노드까지의 최단 경로를 계산하고 저장
void bfs(int n) {
    bool visit[60001] = { false };
    queue<pair<int, int>> q;
    q.push({n, 0});
    visit[n] = true;

    while (!q.empty()) {
        int x = q.front().first;  // 현재 노드
        int result = q.front().second;  // 지금까지 계산된 거리
        q.pop();

        // 현재 노드에서 갈 수 있는 모든 노드로 이동
        for (int it : tree[x]) {
            if (!visit[it]) {
                visit[it] = true;
                node_result[{n, it}] = result + node[{x, it}];
                node_result[{it, n}] = result + node[{x, it}];  // 양방향
                q.push({it, result + node[{x, it}]});
            }
        }
    }
}

int main() {
    int N, x, y, value;
    cin >> N;  // 정점(노드) 수

    for (int i = 1; i <= N; i++) {
        cin >> people[i];  // 각 노드에 사는 깐프의 수
    }

    // 트리 구조 입력
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y >> value;
        node[{x, y}] = value;  // 간선의 가중치
        node[{y, x}] = value;  // 양방향
        tree[x].push_back(y);  // 트리 구조에 간선 추가
        tree[y].push_back(x);  // 트리 구조에 간선 추가
    }

    // 모든 노드에서 다른 모든 노드로의 최단 경로를 한 번만 계산
    for (int i = 1; i <= N; i++) {
        bfs(i);  // 각 노드에서 다른 모든 노드로의 최단 경로를 계산
    }

    int event_num;
    cin >> event_num;  // 이벤트 수

    // 이벤트 처리
    for (int i = 1; i <= event_num; i++) {
        int event, vi, gi;
        cin >> event;

        if (event == 1) {  // 축제 이벤트
            cin >> vi;  // 축제 목적지
            long long result = 0;

            // 각 노드에서 축제 목적지까지의 최단 경로를 이용해 부담 계산
            for (int j = 1; j <= N; j++) {
                if (j != vi) {
                    result += node_result[{j, vi}] * people[j];  // 최단 거리 * 사람 수
                }
            }

            cout << result << endl;
        }
        else if (event == 2) {  // 깐프 추가 이벤트
            cin >> vi >> gi;
            people[vi] += gi;  // 해당 노드의 깐프 수 증가
        }
    }

    return 0;
}
