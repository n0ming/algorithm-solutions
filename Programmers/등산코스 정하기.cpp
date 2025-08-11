#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<int, int>> graph[50001];
bool isGate[50001];
bool isSummit[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // 초기화
    for (auto& p : paths) {
        int a = p[0], b = p[1], w = p[2];
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for (int g : gates) isGate[g] = true;
    for (int s : summits) isSummit[s] = true;

    vector<int> intensity(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // 출입구들을 시작점으로 등록
    for (int g : gates) {
        intensity[g] = 0;
        pq.push({0, g});
    }

    while (!pq.empty()) {
        auto [curIntensity, cur] = pq.top(); pq.pop();
        if (intensity[cur] < curIntensity) continue;
        if (isSummit[cur]) continue;  

        for (auto [next, w] : graph[cur]) {
            if (isGate[next]) continue; // 다른 출입구로 가는 건 제외
            int nextIntensity = max(curIntensity, w);
            if (intensity[next] > nextIntensity) {
                intensity[next] = nextIntensity;
                pq.push({nextIntensity, next});
            }
        }
    }

    // 산봉우리 중에서 가장 좋은 것 선택
    sort(summits.begin(), summits.end());
    int minSummit = 0, minIntensity = INT_MAX;

    for (int s : summits) {
        if (intensity[s] < minIntensity) {
            minSummit = s;
            minIntensity = intensity[s];
        }
    }

    return {minSummit, minIntensity};
}
