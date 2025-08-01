#include <iostream>
#include <string>
#include<vector>
#include<map>
#include<math.h>

int N, M;
int answer = 0;
std::vector<std::vector<char>> maps;
bool visited[26];
void print_debug() {
	for (auto map : maps) {
		for (int i = 0; i < M; i++) std::cout << map[i] << " ";
		std::cout << std::endl;
	}
}
void init() {
	std::cin >> N >> M;
	maps.resize(N + 1, std::vector<char>(M + 1, 0));

	std::string line;
	for (int i = 0; i < N; i++) {
		std::cin >> line;
		for (int j = 0; j < M; j++) {
			maps[i][j] = line[j];
		}
	}
}

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 }; 

void dfs(int x, int y, bool visited[26], int cost) {

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= N || ny >= M || nx<0 || ny<0) continue;

		char c = maps[nx][ny];
		if (visited[c - 'A']) continue;

		visited[c-'A'] = true;

		dfs(nx, ny, visited, cost + 1);

		visited[c - 'A'] = false;
	}
	answer = std::max(answer, cost);
}
int main() {

	init();
	//print_debug();
	visited[maps[0][0] - 'A'] = 1;
	dfs(0,0,visited,1);

	std::cout << answer;
	return 0;

}
