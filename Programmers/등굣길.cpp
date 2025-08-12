#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1000000007;
int dist[101][101];
long long ways[101][101];
int dx[] = {0, 1};
int dy[] = {1, 0};

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<bool>> water(m, vector<bool>(n, false));
    for (auto &p : puddles) {
        water[p[0] - 1][p[1] - 1] = true;
    }

    // BFS로 최단 거리 계산
    fill(&dist[0][0], &dist[0][0] + 101*101, -1);
    queue<pair<int,int>> q;
    dist[0][0] = 0;
    ways[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (water[nx][ny]) continue;

            if (dist[nx][ny] == -1) { // 처음 방문
                dist[nx][ny] = dist[x][y] + 1;
                ways[nx][ny] = ways[x][y];
                q.push({nx, ny});
            } else if (dist[nx][ny] == dist[x][y] + 1) {
                ways[nx][ny] = (ways[nx][ny] + ways[x][y]) % MOD;
            }
        }
    }

    return ways[m-1][n-1] % MOD;
}
