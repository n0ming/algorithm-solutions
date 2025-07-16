#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> answer;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q1; //큰 값 최소힙
	priority_queue<int> q2; //작은 값 최대힙
	bool check = true;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (check) {
			q2.push(num);
			check = false;
		}
		else {
			check = true;
			q1.push(num);
		}

		if (q1.empty()) {
			answer.push_back(q2.top());
			continue;
		}

		int low = q2.top();
		int high = q1.top();
		if (low > high) {
			q2.pop(); q1.pop();
			q2.push(high);
			q1.push(low);
		}

		if (q1.size() == q2.size()) {
			if (q1.top() > q2.top()) answer.push_back(q2.top());
			else answer.push_back(q1.top());
		}
		else {
			answer.push_back(q2.top());
		}

	}

	for (auto ans : answer) {
		cout << ans << "\n";
	}
}
