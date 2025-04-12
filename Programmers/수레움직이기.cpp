#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> maze;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Puzzle {
public:
    int xRed, yRed, xBlue, yBlue, round;
    bool RedFinish, BlueFinish;
    vector<vector<int>> red_visited;
    vector<vector<int>> blue_visited;

    Puzzle(int Rx, int Ry, int Bx, int By)
        : xRed(Rx), yRed(Ry), xBlue(Bx), yBlue(By), round(0), RedFinish(false), BlueFinish(false),
          red_visited(maze.size(), vector<int>(maze[0].size(), 0)),
          blue_visited(maze.size(), vector<int>(maze[0].size(), 0)) {
        red_visited[Rx][Ry] = 1;
        blue_visited[Bx][By] = 1;
    }

    Puzzle(const Puzzle& other) = default;

    bool isRedFinish() {
        if (maze[xRed][yRed] == 3) {
            RedFinish = true;
            return true;
        }
        return false;
    }

    bool isBlueFinish() {
        if (maze[xBlue][yBlue] == 4) {
            BlueFinish = true;
            return true;
        }
        return false;
    }

    bool isPossible(int x, int y, int color) {
        if (x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size()) return false; //벗어나면 안됨
        if (maze[x][y] == 5) return false; //벽이면 안됨
        if (color == 0 && red_visited[x][y]) return false; //중복 방문 안됨
        if (color == 1 && blue_visited[x][y]) return false; //중복방문안됨
        return true;
    }
};

int solution(vector<vector<int>> maze_buf) {
    maze = maze_buf;
    int xSize = maze.size(), ySize = maze[0].size();

    int Rx, Ry, Bx, By;
    for (int i = 0; i < xSize; i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            if (maze[i][j] == 1) {
                Rx = i;
                Ry = j;
            } else if (maze[i][j] == 2) {
                Bx = i;
                By = j;
            }
        }
    }

    queue<Puzzle> q;
    q.emplace(Rx, Ry, Bx, By);

    while (!q.empty()) {
        Puzzle puzzle = q.front();
        q.pop();

        if (puzzle.RedFinish && puzzle.BlueFinish) {
            return puzzle.round;
        }

        // 16가지 방향 조합 (R, B 각각 4방향 + 제자리 포함)
        for (int i = 0; i < 4; ++i) {
            int rnx = puzzle.xRed, rny = puzzle.yRed;
            if (!puzzle.RedFinish) {
                int tx = puzzle.xRed + dx[i];
                int ty = puzzle.yRed + dy[i];
                if (puzzle.isPossible(tx, ty, 0)) {
                    rnx = tx;
                    rny = ty;
                }
            }

            for (int j = 0; j < 4; ++j) {
                int bnx = puzzle.xBlue, bny = puzzle.yBlue;
                if (!puzzle.BlueFinish) {
                    int tx = puzzle.xBlue + dx[j];
                    int ty = puzzle.yBlue + dy[j];
                    if (puzzle.isPossible(tx, ty, 1)) {
                        bnx = tx;
                        bny = ty;
                    }
                }

                // 충돌 방지
                if (rnx == bnx && rny == bny) continue;
                if (rnx == puzzle.xBlue && rny == puzzle.yBlue &&
                    bnx == puzzle.xRed && bny == puzzle.yRed) continue;

                // 다음 상태 생성
                Puzzle next = puzzle;
                next.round++;
                bool movedRed = false, movedBlue = false;  // 이동 여부 추적

                // 빨간색 수레가 움직였다면
                if ((rnx != puzzle.xRed || rny != puzzle.yRed)) {
                    next.xRed = rnx;
                    next.yRed = rny;
                    next.red_visited[rnx][rny] = 1;
                    next.isRedFinish();
                    movedRed = true;
                }

                // 파란색 수레가 움직였다면
                if ((bnx != puzzle.xBlue || bny != puzzle.yBlue)) {
                    next.xBlue = bnx;
                    next.yBlue = bny;
                    next.blue_visited[bnx][bny] = 1;
                    next.isBlueFinish();
                    movedBlue = true;
                }

                // 빨간색 또는 파란색이 움직였으면 큐에 추가
                if ((movedRed || puzzle.RedFinish) && (movedBlue || puzzle.BlueFinish)) {
                    q.push(next);
                }
            }
        }
    }

    return 0;
}
