#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> dp;//first=day second=cost
int result = 0;
int N;

void dfs(int day, int cost) {
	if (day >= N) {
		result = max(cost, result);
		return;
	}

	int nday = day + dp[day].first;
	int ncost = cost + dp[day].second;
	if(nday<= N) dfs(nday, ncost);

	dfs(day + 1, cost);
}
int main() {
	cin >> N;
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> dp[i].first >> dp[i].second;	
	}

	dfs(0, 0);
	cout << result << "\n";
}
