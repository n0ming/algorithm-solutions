#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int OFFSET = 50;
vector<vector<int>> dp(1001, vector<int>(101, 10000000)); 
int outTemp, _t1, _t2, _a, _b, result = 10000000;

int nextTemp(int curTemp) {
    int gap = outTemp - curTemp;
    if (gap > 0) return curTemp + 1;
    if (gap < 0) return curTemp - 1;
    return curTemp;
}

void dfs(int idx, int cost, int curTemp, const vector<int> onboard) {
    if (curTemp < -50 || curTemp > 50) return;

    if (idx == onboard.size()) {
        result = min(result, cost);
        return;
    }

    if (onboard[idx] == 1 && (curTemp < _t1 || curTemp > _t2)) return;

    if (dp[idx][curTemp + OFFSET] <= cost) return;
    dp[idx][curTemp + OFFSET] = cost;

    dfs(idx + 1, cost, nextTemp(curTemp), onboard);         // 에어컨 off
    dfs(idx + 1, cost + _b, curTemp, onboard);              // 유지
    dfs(idx + 1, cost + _a, curTemp - 1, onboard);          // 에어컨 -1
    dfs(idx + 1, cost + _a, curTemp + 1, onboard);          // 에어컨 +1
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    _t1 = t1;
    _t2 = t2;
    _a = a;
    _b = b;
    outTemp = temperature;
    dfs(0, 0, temperature, onboard);
    return result;
}
