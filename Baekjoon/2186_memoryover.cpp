#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

int N, M, K;
char arr[101][101];
string target;
int result = 0;

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

void solve(int x, int y) {
	queue <pair<pair<int,int>, int>> q;
	q.push({{ x, y }, 0});

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cur = q.front().second;
		q.pop();

		if (cur == target.size()-1) {
			result++;
			continue;
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int k = 1; k <= K; k++) {
					int nx = x + dx[i] * k;
					int ny = y + dy[i] * k;
					if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == target[cur+1]) {
						q.push({ { nx,ny }, cur+ 1});
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;
	if (N < 1 || N>100 || M < 1 || M>100 || K < 1 || K>5) return 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> target;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == target[0]) solve(i, j);
		}
	}

	cout << result <<endl;

	return 0;
}
