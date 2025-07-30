#include <iostream>
#include <vector>
#include<queue>

using namespace std;

struct Node {
	int x, y, cost;
};

vector<vector<int>> maps(101, vector<int>(100, 0));
vector<vector<int>> visited(101, vector<int>(100, 0));
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1, -1 };

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            maps[i][j] = line[j] - '0';  
        }
	}
}

int main() {
	init();

	queue<Node> q;
	q.push(Node{ 0,0,1 });
	visited[0][0] = 1;

	while (!q.empty()) {
		Node cur = q.front(); q.pop();

		int curX = cur.x;
		int curY = cur.y;
		int curCost = cur.cost;

		if (curX == N - 1 && curY == M - 1) {
			cout << curCost << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || maps[nextX][nextY]==0 || visited[nextX][nextY])
			{
				continue;
			}

			visited[nextX][nextY] = 1;
			q.push(Node{ nextX,nextY,curCost + 1 });
		}

	}
	return 0;
}
