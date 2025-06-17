#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool check = false;

void dfs(int x, int y, int size, vector<vector<int>> &apt, int* count_house)
{
    (*count_house)++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;
        if (apt[nx][ny] == 1) {
            apt[nx][ny]++;
            dfs(nx, ny, size, apt, count_house);
        }
    }
}
int main() {
    vector<int> answer;

    int num;
    cin >> num;

    vector<vector<int>> apt(25, vector<int>(25, 0));
    for (int i = 0; i < num; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < num; j++) {
            apt[i][j] = line[j]-'0';
        }
    }

    int n = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (apt[i][j] != 1) continue;

            apt[i][j]++;

            int count_house = 0;
            dfs(i, j, num, apt, &count_house);
            answer.push_back(count_house);
            n++;
        }
    }

    sort(answer.begin(), answer.end());
    cout << n << endl;
    for (auto ele : answer) cout << ele << endl;
}
