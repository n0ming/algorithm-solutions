#include <iostream>
using namespace std;

int board[101][101];       
int dx[] = {0, 0, 1, -1};   
int dy[] = {1, -1, 0, 0};

void colorPaper(int x, int y) {
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++) {
            board[i][j] = 1;
        }
    }
}

int main() {
    int n, answer =0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        colorPaper(x, y);
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (board[i][j] == 1) {       
                answer++;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
