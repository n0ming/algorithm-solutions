// 오름차순으로 진행한 뒤에 시간을 차례대로 합하면 그것이 총 걸리는 시간이다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> arr;
int main() {
   cin >> N;

   for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
   }
   sort(arr.begin(), arr.end());

   int total = 0;
   int result = 0;
   for (int j = 0; j < N; j++) {
      for (int i = 0; i <= j; i++) {
         total += arr[i];
      }
   }

   cout << total << "\n";
   return 0;
}
