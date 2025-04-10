#include <iostream>
#include <vector>
using namespace std;

int first, second;
int K, V, E;
vector<int> node[20001];
int color[20001];

bool dfs(int a, int b) {
	color[a] = b;

	for (int next : node[a]) {
		if (color[next] == 0) {
			if (!dfs(next, -b)) {
				return false;
			}
		}
		else if (color[a] == color[next]) return false;
	}
	return true;
}
int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;

		//초기화
		for (int i = 1; i <= V; i++) {
			node[i].clear();
			color[i] = 0;
		}

		//입력받기
		for (int i = 0; i < E; i++) {
			cin >> first >> second;
			node[first].push_back(second);
			node[second].push_back(first);
		}

		bool ischeck = true;
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				if (!dfs(i, 1)) {
					ischeck = false;
					break;
				}
			}
		}
		if (ischeck) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
