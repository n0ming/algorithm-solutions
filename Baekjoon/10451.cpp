#include <iostream>
#include <queue>
using namespace std;

int N, result;
//queue <pair<bool, pair<int,int>>> arr;
//vector <int> node[2000];
int node[1001];
int visit[1001] = { 0 };

void solve(int a) {
	visit[a] = 1;
	if (!visit[node[a]]) {
		solve(node[a]);
	}
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int node_n;
		cin >> node_n;

		for (int j = 1; j <= node_n; j++) {
			cin >> node[j];
			//arr.push({ false, {first, second} });
		}
		result = 0;
		fill(visit, visit+node_n+1, 0); //시작지점, 시작지점+끝, 0으로 초기화

		for (int j = 1; j <= node_n; j++) {
			if (!visit[j]) {
				result++;
				solve(j);
			}
		}
		cout << result << endl;
	}
}
