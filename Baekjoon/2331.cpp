//set에 d[n]값을 넣고 이후에 들어오는 값들이 set안에 있는 값인지 확인 
// 있는 값이면 그 다음 값도 존재하는지 보고 존재하면 그때부터는 반복 수열 시작으로 판단
//확인된 첫 값의 위치(몇번째)를 출력하면 됨

#include <iostream>
#include <map>
#include <math.h>
using namespace std;

class solve {
private: 
	int A, P;
	map<int, int> result;
	//set <int> result;

public:
	void InputAP() {
		cin >> A >> P;
	}

	void CalcLocation() {
		int current = A;
		int index = 0;
		while (result.find(current) == result.end()) { //존재하지 않으면 end()반환
			result[current]=index++;
			current = getNextNumber(current);
		}

		auto it = result.find(current);
		cout << result[current] << endl;
	}
	int getNextNumber(int num) {
		int total = 0;
		while (num > 0) {
			int digit = num % 10;
			total += pow(digit, P);
			num /= 10;
		}
		return total;
	}
};

int main() {
	solve s;
	s.InputAP();
	s.CalcLocation();
	return 0;
}
