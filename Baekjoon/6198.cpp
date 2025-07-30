#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int len;
vector<int> buildings;
map<int, int> m;

void init() {
	cin >> len;
	buildings.resize(len);
	for (int i = 0; i < len; i++) {
		int num;
		cin >> num;
		buildings[i] = num;
		m[num] = i;
	}
}

//정렬
int main() {
	init();

	vector<int> sorted_buildings(buildings);
	sort(sorted_buildings.begin(), sorted_buildings.end());
	for (int i = 1; i < len; i++) {
		vector<int> sorted_buildings(buildings.begin() + i, buildings.end());
		sort(sorted_buildings.begin(), sorted_buildings.end());

		auto result = lower_bound(sorted_buildings.begin(), sorted_buildings.end(), buildings[i-1]);
		
		if (result != sorted_buildings.end()) {
			int idx = result - sorted_buildings.begin();
			cout << sorted_buildings[idx] << " " << m[sorted_buildings[idx]]-i << endl;
		}
		else cout << "1개" << endl;
		
	}
}
