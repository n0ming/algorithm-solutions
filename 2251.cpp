#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

set<int> result;
map <string, bool> m;
int abc[3] = { 0 };

void solve(int a, int b, int c) {
	if (a > abc[0] || a<0 || b>abc[1] || b < 0 || c>abc[2] || c < 0) return;
	string total = to_string(a) + to_string(b) + to_string(c);
	
	if (m[total]) return;
	m[total] = true;

	if (a ==0 ) result.insert(c);
	solve(a - min(a, abc[1] - b), b + min(a, abc[1] - b), c); // A -> B
	solve(a - min(a, abc[2] - c), b, c + min(a, abc[2] - c)); // A -> C
	solve(a + min(b, abc[0] - a), b - min(b, abc[0] - a), c); // B -> A
	solve(a, b - min(b, abc[2] - c), c + min(b, abc[2] - c)); // B -> C
	solve(a + min(c, abc[0] - a), b, c - min(c, abc[0] - a)); // C -> A
	solve(a, b + min(c, abc[1] - b), c - min(c, abc[1] - b)); // C -> B
}
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> abc[i];
		/*if (abc[i] < 1 || abc[i]>200) {
			cout << "A, B, C의 용량은 1이상 200리터 이하여야 합니다." << endl;
			return 0;
		}*/
	}
	solve(0, 0, abc[2]);

	for (auto s : result) {
		cout << s << " ";
	}
	cout << endl;
	
	return 0;
}
