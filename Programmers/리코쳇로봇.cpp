#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x;
    int y;
    int count;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool checkBlock(int x, int y, int xsize, int ysize, vector<string>& board) {
    if (x < 0 || x >= xsize || y < 0 || y >= ysize) return true;
    if (board[x][y] == 'D') return true;
    return false;
}

int solution(vector<string> board) {
    int xB, yB;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') {
                xB = i;
                yB = j;
            }
        }
    }

    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    queue<Node> q;
    q.push({xB, yB, 0});
    visited[xB][yB] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (board[cur.x][cur.y] == 'G') {
            return cur.count;
        }

        for (int i = 0; i < 4; i++) {
            Node ncur = cur;

            while (!checkBlock(ncur.x + dx[i], ncur.y + dy[i], board.size(), board[0].size(), board)) {
                ncur.x += dx[i];
                ncur.y += dy[i];
            }

            if (!visited[ncur.x][ncur.y]) {
                visited[ncur.x][ncur.y] = true;
                q.push({ncur.x, ncur.y, cur.count + 1});
            }
        }
    }

    return -1;
}
